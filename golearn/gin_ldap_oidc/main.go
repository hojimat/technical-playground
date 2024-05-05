package main

import (
	"github.com/gin-gonic/gin"

	"authapp/authn"
)

func main() {
	oidcauth := authn.NewAuthenticator()
	// Connect to the LDAP server
	ldapm := authn.NewLDAPManager("ldap://ldapserver:1389", "cn=admin,dc=fdtech,dc=de", "admin123")
	defer ldapm.Close()

	router := gin.Default()

	router.GET("/", func(c *gin.Context) { c.JSON(200, gin.H{"title": "homepage"}) })
	router.GET("/login", func(c *gin.Context) { oidcauth.HandleMicrosoftLogin(c) })
	router.GET("/callback", func(c *gin.Context) { oidcauth.HandleMicrosoftCallback(c) })

	router.GET("/search", func(c *gin.Context) { ldapm.HandleSearch(c) })
	router.POST("/adduser", func(c *gin.Context) { ldapm.HandleAddEntry(c) })

	router.Run(":8080")
}
