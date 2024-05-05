# Type definition with empty bases and dict
Foo = type('Fame', (), {} )

print(type(Foo))
print(type(Foo()))
print(Foo)
print(Foo.__bases__)
print(Foo.__dict__)