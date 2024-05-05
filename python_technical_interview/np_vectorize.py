import numpy as np

def ordinary_func(r: float):
    return 3.14 * r**2

vectorized_func = np.vectorize(ordinary_func)

radii = [1.2, 2.3, 3.4, 4.5]

#result = ordinary_func(radii)
result = vectorized_func(radii)
print(result)