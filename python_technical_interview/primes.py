from time import time
import math 
# rules:
# 1 is not prime; 2 is prime and 3 is prime are givens
# every prime number is 1 or 5 mod 6

T = 50000+1
myrange = [3]

myrange += (list(range(5,T))[::6])
myrange += (list(range(7,T))[::6])

time0 = time()
primes = [2]
#for i in myrange:
for i in range(3,T):
    isprime = True
    for j in range(2,i):
        if i%j ==0:
            isprime = False
            break
    if isprime:
        primes.append(i)

time1 = time()
print(f"\n{time1-time0} seconds")
#print(primes)


