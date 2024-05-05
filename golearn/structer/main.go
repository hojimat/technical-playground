package main

import "fmt"

type BookInfo struct {
    title string
    *Author
    Country
}

type Author struct {
    name string
    age int8
}

type Country struct {
    cname string
    population int32
}


func main() {
    rowling := &Author {"J.K. Rowling", 47}
    england := Country {"England", 78000000}

    bookinfo := BookInfo {"harry potter", rowling, england}

    fmt.Println(bookinfo.name)
}
