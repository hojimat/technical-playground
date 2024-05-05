class MyMeta(type):
    def __init__(cls, name, bases, attrs):
        attrs['mymeta'] = "This is a class-level meta attribute!"
        super().__init__(name, bases, attrs)


class Student(metaclass=MyMeta):
    def __init__(self, name):
        self.name = name
    
    def greet(self):
        print("Hello! My name is a student!")


a = Student("Andy")
print(a.name)
print(Student.__dict__)
