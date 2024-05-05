# Type definition with inheritance and empty dict
Foo = type('Fame', (), {} )
Bar = type('Bame', (Foo,), {'attr':100} )
a = Bar()

print(type(Bar))
print(type(a))
print(a.attr)
print(a.__class__)
print(Bar.__name__)
print(Bar.__bases__)
print(Bar.__dict__)