class Person:
    def __init__(self, age, name):
        self.age = age
        self.name = name

    def greet(self):
        return f'Hi, my name is {self.name}'


class Teacher(Person):
    def __init__(self, age):
        super().__init__(age=age, name='John')


if __name__=='__main__':
    person = Person(12,'paul')
    teacher = Teacher(32)
    breakpoint()
