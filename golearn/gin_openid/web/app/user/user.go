package user

import (
	"net/http"

	"github.com/gin-contrib/sessions"
	"github.com/gin-gonic/gin"
)

// Handler for our logged-in user page.
func Handler(ctx *gin.Context) {
	session := sessions.Default(ctx)
	profile_name := session.Get("profile_name")
	profile_email := session.Get("profile_email")

	ctx.HTML(http.StatusOK, "user.html", gin.H{"profile_name": profile_name, "profile_email": profile_email})
}
