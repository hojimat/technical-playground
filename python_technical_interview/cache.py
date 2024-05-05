class cacher:
    def __init__(self, func):
        self.memory = {}
        self.func = func
    
    def __call__(self, *args, **kwargs):
        key = str(args) + str(kwargs)
        if key in self.memory:
            return self.memory[key]
        else:
            output = self.func(*args, **kwargs)
            self.memory[key] = output
            return output


@cacher
def fib(n):
    if n==0 or n==1:
        return 1
    else:
        return fib(n-1) + fib(n-2)

if __name__=='__main__':
    for i in range(50):
        print(fib(i))
