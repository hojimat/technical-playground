class Student:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def introduce(self):
        print(f"Hello, my name is {self.name} and I am {self.age} years old!")



def vorstellen(self):
    print(f"Hallo, ich heisse {self.name} und ich bin {self.age} Jahre alt!")

bob = Student("Bob", 21)
bob.introduce()

Student.introduce = vorstellen
bob.introduce()
james = Student("james", 27)
james.introduce()
