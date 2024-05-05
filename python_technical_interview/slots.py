class MyClass():
    __slots__ = ['a','b']
    
    def __init__(self):
        self.a = 132
        self.b = 23
        self.c = 324

if __name__=="__main__":
    instance = MyClass()
    print(instance.__dir__())
