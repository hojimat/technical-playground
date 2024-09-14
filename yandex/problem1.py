with open("input.txt", "r") as f:
    line = f.readline()
    a, b = map(int, line.split())

with open("output.txt", "w") as f:
    mysum = a+b
    f.write(str(mysum))