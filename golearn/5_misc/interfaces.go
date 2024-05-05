package main

import (
        "fmt"
        "math"
)

/* define an interface */
type Shape interface {
        area() float64
}

type Circle struct {
        x, y, radius float64
}

type Rectangle struct {
        w, h float64
}

func(crc Circle) area() float64 {
        return math.Pi * crc.radius * crc.radius
}

func(rct Rectangle) area() float64 {
        return rct.w * rct.h
}

func getArea(shp Shape) float64 {
        return shp.area()
}


func main() {
        myCircle := Circle{x:0,y:0,radius:10}
        myRectangle := Rectangle{w:5,h:4}

        fmt.Printf("circle area is: %f\n", getArea(myCircle))
        fmt.Printf("rectangle area is %f\n", getArea(myRectangle))
}
