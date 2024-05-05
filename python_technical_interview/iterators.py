def f(x):
    for i in range(x):
        yield i**3

for x in f(5):
    print(x)