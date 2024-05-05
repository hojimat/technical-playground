package authn

import (
	"fmt"
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/go-ldap/ldap/v3"
)

type LDAPManager struct {
	conn *ldap.Conn
}

func NewLDAPManager(server string, bindDN string, bindPassword string) *LDAPManager {
	conn, err := ldap.DialURL(server)
	if err != nil {
		log.Fatalf("Failed to connect to LDAP server: %v", err)

	}

	err = conn.Bind(bindDN, bindPassword)
	if err != nil {
		log.Fatalf("Failed to authenticati at LDAP server: %v", err)
	}

	return &LDAPManager{conn: conn}
}

func (ldapm *LDAPManager) Close() {
	if ldapm.conn != nil {
		ldapm.conn.Close()
	}
}

func (ldapm *LDAPManager) search(baseDN, filter string) ([]*ldap.Entry, error) {

	searchRequest := ldap.NewSearchRequest(
		baseDN, //"dc=fdtech,dc=de", // Base DN
		ldap.ScopeWholeSubtree, ldap.NeverDerefAliases, 0, 0, false,
		filter,                       //"(objectClass=inetOrgPerson)", // Filter
		[]string{"dn", "cn", "mail"}, // Attributes to retrieve
		nil,
	)

	// Perform the search
	searchResult, err := ldapm.conn.Search(searchRequest)
	if err != nil {
		return nil, err
	}

	// Print out the entries
	return searchResult.Entries, nil

}

func (ldapm *LDAPManager) HandleSearch(c *gin.Context) {
	baseDN := c.DefaultQuery("baseDN", "dc=fdtech,dc=de")
	filter := c.DefaultQuery("filter", "(objectClass=inetOrgPerson)")

	entries, err := ldapm.search(baseDN, filter)
	if err != nil {
		log.Printf("LDAP search failed: %v", err)
		c.Redirect(http.StatusTemporaryRedirect, "/")
		return
	}

	c.JSON(http.StatusOK, entries)
}

func (ldapm *LDAPManager) addEntry(dn string, attributes map[string][]string) error {
	addRequest := ldap.NewAddRequest(dn, nil)
	for key, vals := range attributes {
		addRequest.Attribute(key, vals)
	}

	if err := ldapm.conn.Add(addRequest); err != nil {
		return err
	}

	return nil
}

type AddEntryRequest struct {
	DN         string              `json:"dn"`
	Attributes map[string][]string `json:"attributes"`
}

func (ldapm *LDAPManager) HandleAddEntry(c *gin.Context) {
	var data AddEntryRequest
	if err := c.ShouldBindJSON(&data); err != nil {
		log.Printf("LDAP Bind JSON failed: %v", err)
		c.Redirect(http.StatusTemporaryRedirect, "/")
		return
	}

	fmt.Printf("read these")
	fmt.Printf(data.DN)
	for key, val := range data.Attributes {
		fmt.Printf("%v : %v", key, val)
	}
	fmt.Printf("----")
	if err := ldapm.addEntry(data.DN, data.Attributes); err != nil {
		log.Printf("LDAP add entry failed: %v", err)
		c.Redirect(http.StatusTemporaryRedirect, "/")
		return
	}

	c.JSON(http.StatusOK, gin.H{"status": "entry added successfully"})
}
