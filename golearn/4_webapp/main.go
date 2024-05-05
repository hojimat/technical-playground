package main

import (
	"log"
	"net/http"
	"os"

	"github.com/joho/godotenv"
)

func indexHandler(w http.ResponseWriter, r *http.Request) {
	w.Write([]byte("<h1>Hello worldie</h1>"))
}

func main() {
	err := godotenv.Load()
	if err != nil {
		log.Println("error loading .env file")
	}

	port := os.Getenv("PORT")
	if port == "" {
		port = "3001"
	}

	mux := http.NewServeMux()
	mux.HandleFunc("/", indexHandler)

	http.ListenAndServe(":"+port, mux)
}
