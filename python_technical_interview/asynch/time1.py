# How it works synchroniously
import time

def func1(x):
    print(x**2)
    time.sleep(3)
    print('func1 finished')

def func2(x):
    print(x**0.5)
    time.sleep(3)
    print('func2 finished')


def main():
    func1(4)
    func2(4)

if __name__=='__main__':
    start = time.time()
    main()
    end = time.time()
    print(end-start)