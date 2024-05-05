class cache:
    def __init__(self, func):
        self.cache = {}
        self.func = func

    def __call__(self, *args, **kwargs):
        key = str(args) + str(kwargs)
        if key in self.cache:
            return self.cache[key]
        
        output = self.func(*args, **kwargs)
        self.cache[key] = output
        return output

@cache
def fib(n: int) -> int:
    if n<=0:
        print("Please enter a valid number!")
        return
    elif n==1 or n==2:
        return 1
    else:
        return fib(n-1) + fib(n-2)
    
if __name__=="__main__":
    for i in range(1,50):
        print(fib(i))











'''
class cacher:
    def __init__(self, func):
        self.cache = {}
        self.func = func

    def __call__(self, *args, **kwargs):
        key = str(args) + str(kwargs)
        if key in self.cache:
            return self.cache[key]
        value = self.func(*args, **kwargs)
        self.cache[key] = value
        return value





@cacher
def fib(n):
    if n==0 or n==1:
        return 1
    else:
        return fib(n-1) + fib(n-2)

if __name__=='__main__':
    for i in range(50):
        print(fib(i))





























class cacher:
    def __init__(self, func ):
        self.cache = {}
        self.func = func

    def __call__(self, *args, **kwargs):
        key = str(args) + str(kwargs)
        if key in self.cache:
            return self.cache[key]

        value = self.func(*args, **kwargs)
        self.cache[key] = value
        return value


@cacher
def fib(N : int) -> int:
    if N==0 or N==1:
        return 1
    else:
        return fib(N-1) + fib(N-2)
        

for i in range(50):
    print(fib(i))

print(fib.cache)
'''
