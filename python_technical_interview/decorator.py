from time import time

def timer(func):
    def wrapper(*args, **kwargs):
        time0 = time()
        output = func(*args, **kwargs)
        time1 = time()
        duration = round(time1-time0,3)
        print(f"{duration} seconds")
        return output
    return wrapper

def arger(func):
    def wrapper(*args, **kwargs):
        print(f"The arguments are {args}")
        func(*args, **kwargs)
    return wrapper

@timer
@arger
def myfunc(N):
    total = 0
    for i in range(N):
        total += i
    print(total)
    return total

if __name__=='__main__':
    myfunc(10000)
    
