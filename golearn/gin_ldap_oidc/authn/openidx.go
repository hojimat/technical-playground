package authn

import (
	"context"
	"crypto/rand"
	"crypto/sha256"
	"encoding/base64"
	"fmt"
	"log"
	"net/http"

	"github.com/coreos/go-oidc"
	"github.com/gin-gonic/gin"
	"golang.org/x/oauth2"
	"golang.org/x/oauth2/microsoft"
)

// Declare an Authenticator struct to store the configs and token verifiers
type Authenticator struct {
	OAuthConfig *oauth2.Config
	Verifier    *oidc.IDTokenVerifier
}

// Function to initalize the Authenticator struct
func NewAuthenticator() *Authenticator {
	// Set OIDC provider
	provider, err := oidc.NewProvider(context.Background(), "https://login.microsoftonline.com/CLIENTID/v2.0")
	if err != nil {
		log.Fatalf("Failed to get OpenID Connect Provider: %v", err)
	}

	// Set OAuth configs
	oauthConfig := &oauth2.Config{
		RedirectURL:  "http://localhost:8080/callback",
		ClientID:     "CLIENTID",
		ClientSecret: "CLIENTSECRET",
		Scopes:       []string{oidc.ScopeOpenID, "email", "profile"}, // we only need id_token!
		Endpoint:     microsoft.AzureADEndpoint("APPLICATION_ID"),
	}

	// Set a ID token verifier
	verifier := provider.Verifier(&oidc.Config{ClientID: "CLIENTID"})

	// Return the struct
	return &Authenticator{
		OAuthConfig: oauthConfig,
		Verifier:    verifier,
	}
}

// State string for CSRF validity check
var (
	oauthState    string = generateRandomString(16)
	oauthPKCECode string = generateRandomString(32)
	oauthPKCEHash string = hashGivenString(oauthPKCECode)
)

// combine params from config into a working URL and send a GET request
// we don't need an offline access!
// We send State and PKCE challenge and PKCE challenge method along with it
func (auth *Authenticator) HandleMicrosoftLogin(c *gin.Context) {
	url := auth.OAuthConfig.AuthCodeURL(
		oauthState,
		oauth2.AccessTypeOnline,
		oauth2.SetAuthURLParam("code_challenge", oauthPKCEHash),
		oauth2.SetAuthURLParam("code_challenge_method", "S256"),
	)

	c.Redirect(http.StatusTemporaryRedirect, url)
}

// analyze incoming authorization code,
// exchange it with the id_token,
// save the details to the session
func (auth *Authenticator) HandleMicrosoftCallback(c *gin.Context) {
	// Check if state string matches
	state := c.Query("state")
	if state != oauthState {
		log.Printf("Failed CSRF checks")
		c.Redirect(http.StatusTemporaryRedirect, "/")
		return
	}

	oauth2Token, err := auth.OAuthConfig.Exchange(c.Request.Context(), c.Query("code"), oauth2.SetAuthURLParam("code_verifier", oauthPKCECode))
	if err != nil {
		log.Printf("Failed to exchange auth code with a token")
		c.Redirect(http.StatusTemporaryRedirect, "/")
		return
	}

	rawIDToken, ok := oauth2Token.Extra("id_token").(string)
	if !ok {
		log.Printf("No ID token returned")
		c.Redirect(http.StatusTemporaryRedirect, "/")
		return

	}

	idToken, err := auth.Verifier.Verify(context.Background(), rawIDToken)
	if err != nil {
		log.Printf("Failed to verify ID Token: %v", err)
		c.Redirect(http.StatusTemporaryRedirect, "/")
		return
	}

	email, name, err := unpackIDToken(idToken)
	if err != nil {
		log.Printf("Failed to unpack ID Token: %v", err)
		c.Redirect(http.StatusTemporaryRedirect, "/")
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"message": "Authentication successful", "email": email, "name": name})
} // end of callback handler

func unpackIDToken(id_token *oidc.IDToken) (string, string, error) {
	claims := map[string]interface{}{}
	if err := id_token.Claims(&claims); err != nil {
		return "", "", fmt.Errorf("could not unpack ID token: %w", err)
	}

	email, hasEmail := claims["email"].(string)
	if !hasEmail {
		return "", "", fmt.Errorf("email not found in the ID token")
	}

	name, hasName := claims["name"].(string)
	if !hasName {
		return "", "", fmt.Errorf("name not found in the ID token")
	}

	return email, name, nil
}

// Generate a string of "size" random characters
func generateRandomString(size int) string {
	bstring := make([]byte, size)
	rand.Read(bstring)
	return base64.URLEncoding.EncodeToString((bstring))
}

// Hash a given string using SHA-256 and return a string
func hashGivenString(input_string string) string {
	hash_object := sha256.New()
	hash_object.Write([]byte(input_string))
	return base64.URLEncoding.WithPadding(base64.NoPadding).EncodeToString(hash_object.Sum(nil))
}
