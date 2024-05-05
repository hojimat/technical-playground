package main

import (
    "fmt"
    "net/http"

    "github.com/gorilla/mux"
)

func Home(w http.ResponseWriter, r *http.Request) {
    fmt.Fprintf(w, "Hello, world!!!")
}

func CreateBook(w http.ResponseWriter, r *http.Request) {
    fmt.Fprintf(w, "book created!")
}

func ReadBook(w http.ResponseWriter, r *http.Request) {
    vars := mux.Vars(r)
    title := vars["title"]
    fmt.Fprintf(w, "book titled %s details are here....", title)
}


func main() {

    r := mux.NewRouter()

    r.HandleFunc("/", Home)
    r.HandleFunc("/books/{title}", ReadBook)

    fmt.Println("Serving on localhost:8080")
    http.ListenAndServe(":8080", r)

}
