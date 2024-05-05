class Meta(type):
    def __new__(cls, name, bases, dct):
        x = super().__new__(cls, name, bases, dct)
        x.attr = 100
        return x
    
class Foo(metaclass=Meta):
    pass

print(Foo.attr)