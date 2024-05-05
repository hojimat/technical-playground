def f(n):
    return (i**3 for i in range(n))

def g(n):
    for i in range(n):
        yield i**3

for x in g(5):
    print(x)
