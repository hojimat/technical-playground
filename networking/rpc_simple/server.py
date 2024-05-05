from xmlrpc.server import SimpleXMLRPCServer

books = []

def listBooks():
    return books

def addBook(book):
    books.append(book)
    return f"{book} added successfully"


server = SimpleXMLRPCServer(("localhost", 9494))
print("Listening on 9494...")
server.register_function(listBooks, 'listBooks')
server.register_function(addBook, 'addBook')

server.serve_forever()