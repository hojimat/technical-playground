from abc import ABC, abstractmethod

class Obj(ABC):
    @abstractmethod
    def greet(self, x, y):
        print('hello from abstract')
        print(x)

class Job(Obj):
    def greet(self):
        super().greet(10,20)
        print('hi from concrete')




if __name__=='__main__':
    #a = Obj() # cannot instantiate with abstract method
    a = Job()
    a.greet()
    
