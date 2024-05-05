class Foo:
    pass

def new(cls):
    x = object.__new__(cls)
    x.attr = 100
    return x

Foo.__new__ = new # this works
# however, this does not work for type.__new__ redefintion


f = Foo()
print(f.attr)

