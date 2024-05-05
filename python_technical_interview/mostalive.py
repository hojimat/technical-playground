people = [('george', 1901, 1945),
     ('john', 1910, 1985),
     ('paul', 1920, 1985),
     ('ringo', 1930, 1975),
     ('mike', 1940, 1945),
     ('chester', 1950, 1995),
     ('dave', 1960, 1999)]

counter = {}
for i in range(1900,2000):
    counter[i] = 0
    for p in people:
        if i in range(p[1], p[2]+1):
            counter[i] += 1

print(max(counter.items(), key = lambda k: k[1]))
