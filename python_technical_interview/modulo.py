def modulo(a,b):
    r = a
    while r>=b:
        r -= b
    return r

for i in range(1,101):
    if modulo(i,15)==0:
        print("fizzbuzz")
    elif modulo(i,3)==0:
        print("fizz")
    elif modulo(i,5)==0:
        print("buzz")
    else:
        print(i)
