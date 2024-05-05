import numpy as np
import timeit

myvec = np.random.choice(100, 100000)

timeit(lambda: myvec[range(100000)])
