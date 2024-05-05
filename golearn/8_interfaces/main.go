package main

import "fmt"

type Person interface {
	greet() string
}

type Student struct {
	name string
	age  int16
}

func (st *Student) greet() string {
	fmt.Printf("Hi, my name is %v and I am %v years old", st.name, st.age)
	return "done."
}

func newStudent() Person {
	return &Student{"madina", 23}
}

func main() {
	rav := &Student{"ravshanbek", 29}
	rav.greet()

	madi := newStudent()
	madi.greet()
}
