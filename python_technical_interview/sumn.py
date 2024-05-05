from time import time


sum = 0
time0 = time()
#for i in range(10000000):
#    sum += i
sum = 10000000 * 1000001 / 2
time1 = time()

print(f"{time1 - time0} seconds\n")
print(sum)
