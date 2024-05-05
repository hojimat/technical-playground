#include <iostream>
#include "Student.hpp"

using headers::Student;

int main() {
    Student *john = new Student();
    john->sayHi();
    return 0;
}