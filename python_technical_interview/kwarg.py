def printer(*args, **kwargs):
    for i in args:
        print(i)

    for j in kwargs:
        print(f"{j}={kwargs[j]}")
        
printer(2,4,5,5,6,6,42,2.23,"he", sel=43, andy=322)