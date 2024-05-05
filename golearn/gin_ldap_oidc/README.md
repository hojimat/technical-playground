# Go Server with LDAP and OAuth

This program runs a web-server in Golang with user management done via OpenLDAP self-hosted server and two authentication modes -- OAuth2.0 (OpenID Connect) and Username-Password login. The server runs for illustrative purposes using Gin Gonic API framework.

## LDAP(s)
LDAP runs in a `docker-compose.yml` file and has environmental variables defined there. The LDAPS uses SSL/TLS certificates (self-generated for now) which are located in the `./ldap-certificates` folder.



### Examples
Create a text file `new.ltif` and write inside:

```
dn: cn=sebastian hell,dc=fdtech,dc=de
objectClass: inetOrgPerson
cn: Sebastian Hell
sn: Hell
mail: s.hell@fdtech.org
userPassword: password123
```

Then to add a new user run:

```
ldapadd -x -H ldap://ldapserver:1389 -D "cn=admin,dc=fdtech,dc=de" -w admin123 -f new.ldif
```

or send a `POST` request:

```
 curl -X POST 'http://localhost:8080/adduser' \
      -H 'Content-Type: application/json' \
      -d '{
        "dn": "cn=Michael Sachse,ou=users,dc=fdtech,dc=de",
        "attributes": {
            "cn": ["Michael Sachse"],
            "sn": ["Sachse"],
            "mail": ["m.sachse@fdtech.de"],
            "objectClass":["inetOrgPerson"]
          }
        }' 
```



To search all entries:

```
ldapsearch -x -H ldap://ldapserver:1389 -D "cn=admin,dc=fdtech,dc=org" -w admin123 -b "dc=fdtech,dc=org" "(objectClass=*)"
```


