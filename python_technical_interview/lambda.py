from functools import reduce

names= ["Ammy", "Bob", "Cat", "Dan"]
ages = [21, 34, 25, 54]

mapx = map(lambda x: x*2, names)
print(list(mapx))

filterx = filter(lambda x: len(x)==3, names)
print(list(filterx))

reducex = reduce(lambda x,y: x+y, names)
print(reducex)

