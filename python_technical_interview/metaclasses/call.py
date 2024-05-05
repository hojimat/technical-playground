class Foo:
    pass

a = Foo()
b = Foo.__call__() # invokes __new__ and __init__


print(type(a))
print(type(b))