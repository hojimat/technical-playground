class Person:
    def __init__(self, myname, x, y):
        self.name = myname
        self.height = x
        self.weight = y

    def say_hi(self):
        print("Hello, my name is " + self.name)

    def __eq__(self, other):
        if other.name == self.name:
            return True
        
        return False
    
    def __str__(self):
        return f"{self.name} {self.height} {self.weight}"


john = Person("John", 100,30)

john.say_hi()

jack = Person("John", 1030, 30)

jack.__str__()