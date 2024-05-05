#include <iostream>

template<typename T1, typename T2>
class Student{
public:
    T1 age;
    T2 grade;

    Student(T1 x, T2 y)
        : age(x), grade(y) {}

    T1 getAge() {return age;}
};


template<>
class Student<int, int> {
public:
    int age;
    int grade;

    Student(int x, int y)
        : age(x), grade(y+1) {}

    int getAge() {return age+1;}
}


int main() {

    Student<int, float> ravshan(29, 3.53);

    std::cout << ravshan.age;

    return 0;
}