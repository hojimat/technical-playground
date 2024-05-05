package main

import (
	"context"
	"fmt"
	"net/http"

	"github.com/gin-contrib/sessions"
	"github.com/gin-contrib/sessions/cookie"
	"github.com/gin-gonic/gin"
	"golang.org/x/oauth2"
)

// OK
var oauth2Config = &oauth2.Config{
	ClientID:     "",
	ClientSecret: "",
	RedirectURL:  "http://localhost:8080/callback",
	Scopes:       []string{"user.read"},
	Endpoint: oauth2.Endpoint{
		AuthURL:  "https://login.microsoftonline.com/common/oauth2/v2.0/authorize",
		TokenURL: "https://login.microsoftonline.com/common/oauth2/v2.0/token",
	},
}

var oauthStateString = "123456789"

func main() {
	router := gin.Default()
	store := cookie.NewStore([]byte("secret"))
	router.Use(sessions.Sessions("mysession", store))

	router.GET("/", handleMain)
	router.GET("/login", handleLogin)
	router.GET("/callback", handleCallback)

	protected := router.Group("/").Use(authMiddleware())
	protected.GET("/home", handleHome)
	protected.GET("/dashboard", handleDash)
	protected.GET("/logout", handleLogout)

	router.Run(":8080")
}

// OK
func authMiddleware() gin.HandlerFunc {
	return func(c *gin.Context) {
		session := sessions.Default(c)
		if session.Get("user") == nil {
			// User is not logged in
			c.Redirect(http.StatusTemporaryRedirect, "/login")
			c.Abort()
		} else {
			c.Next()
		}
	}
}

func handleMain(c *gin.Context) {
	var htmlIndex string = "<html><body><a href='/home'>Log in via Oauth</a></body></html>"
	c.Writer.Write([]byte(htmlIndex))
}

func handleHome(c *gin.Context) {
	c.JSON(http.StatusOK, gin.H{"message": "You are logged in"})
}

func handleDash(c *gin.Context) {
	c.JSON(http.StatusOK, gin.H{"message": "Welcome to the dashboard. You are allowed to view this page because you are authenticated."})
}

func handleLogin(c *gin.Context) {
	url := oauth2Config.AuthCodeURL(oauthStateString, oauth2.AccessTypeOffline)
	c.Redirect(http.StatusTemporaryRedirect, url)
}

func handleCallback(c *gin.Context) {
	context := context.Background()
	session := sessions.Default(c)

	// Check that the state string matches
	state := c.Query("state")
	if state != oauthStateString {
		fmt.Printf("invalid oauth state, expected '%s', got '%s'\n", oauthStateString, state)
		c.Redirect(http.StatusTemporaryRedirect, "/")
		return
	}

	// Exchange the authorization code for an access token
	code := c.Query("code")
	token, err := oauth2Config.Exchange(context, code)
	if err != nil {
		fmt.Printf("oauthConf.Exchange() failed with '%s'\n", err)
		c.Redirect(http.StatusTemporaryRedirect, "/")
		return
	}

	session.Set("user", token.AccessToken)
	session.Save()
	// The token now contains the access token
	c.Redirect(http.StatusTemporaryRedirect, "/dashboard")
}

func handleLogout(c *gin.Context) {
	session := sessions.Default(c)
	session.Delete("user")
	session.Save()

	c.Redirect(http.StatusTemporaryRedirect, "/")
}
