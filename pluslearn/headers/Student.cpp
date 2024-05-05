#include <iostream>
#include "Student.hpp"

using headers::Student;

Student::Student() {};

void Student::sayHi() {
    std::cout << "Student says hi!\n";
}