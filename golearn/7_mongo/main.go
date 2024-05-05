package main

import (
    "fmt"
    "log"
    "context"

    "go.mongodb.org/mongo-driver/mongo"
    "go.mongodb.org/mongo-driver/mongo/options"
)


func main() {
    mongoURI := "mongodb://localhost:27017"
    client, err := mongo.Connect(context.TODO(), options.Client().ApplyURI(mongoURI))
    if err != nil {
        log.Fatal(err)
    }



    usersCollection := client.Database("testing").Collection("users")

    fmt.Println(usersCollection)
    fmt.Println("Go app working...")
}
