from xmlrpc.client import ServerProxy

s = ServerProxy("http://localhost:9494")

print(s.listBooks())
s.addBook("1984")
s.addBook("Lolita")

print(s.listBooks())
