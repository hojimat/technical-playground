# Type definition with empty bases and function in dict
def f(obj):
    print('attr=', obj.attr)

Foo = type('Fame', (), {'attr': 100, 'attr_val': f })

x = Foo()
print(x.attr)
x.attr_val()