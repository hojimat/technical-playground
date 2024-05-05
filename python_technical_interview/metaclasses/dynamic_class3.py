# Type definition with empty bases and lambda in dict
Foo = type('Fame', (), {'attr': 100, 'attr_val': lambda x: x.attr })

x = Foo()
print(x.attr)
print(x.attr_val())