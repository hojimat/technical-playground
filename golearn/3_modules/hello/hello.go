package main

import (
        "fmt"
        "log"

        "gamma.com/greetings"
)

func main() {
        // Logging options
        log.SetPrefix("grerror: ")
        log.SetFlags(0)

        // A slice of names
        names := []string {"Madina", "Yunus", "Ravshan"}
        
        // Request a greeting message
        messages, err := greetings.Hellos(names)
        if err != nil {
                log.Fatal(err)
        }

        // print the message
        fmt.Println(messages)
}
