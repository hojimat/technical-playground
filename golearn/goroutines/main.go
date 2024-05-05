package main

import "fmt"

func printHello(ch chan int) {
    fmt.Println("printHello()...")
    ch <- 1103
}


func main() {

    ch := make(chan int)

    go func(){
        fmt.Println("inline()...")
        ch <- 1994
    }()

    go printHello(ch)
    fmt.Println("Main function ends.")


    i := <- ch
    fmt.Println("Received: ", i)
    j := <- ch
    fmt.Println("Received: ", j)
}
