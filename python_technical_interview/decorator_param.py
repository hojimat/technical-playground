from time import time

def timer(unit):
    def wrapper(func):
        def inner(*args, **kwargs):
            t0 = time()
            output = func(*args, **kwargs)
            t1 = time()
            duration_sec = round(t1-t0, 3)
            duration_msec = round((t1-t0)*10, 3)

            if unit=="sec":
                print(f"{duration_sec} seconds")
            elif unit=="mil":
                print(f"{duration_msec} milliseconds")

            return output
        return inner
    return wrapper

@timer(unit="mil")
def nsum( n : int ) -> int:
    output = 0

    for i in range(n):
        output += i
        
    return output

if __name__=='__main__':
    print(nsum(1000000))
