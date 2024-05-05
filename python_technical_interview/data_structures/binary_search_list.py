import math

def findval(x, var_list):
    N2 = math.ceil(len(var_list)/2)
    breakpoint() 
    if x == var_list[N2]:
        return N2
    elif x < var_list[N2]:
        return findval(x, var_list[:N2])
    elif x > var_list[N2]:
        return findval(x, var_list[N2:])

if __name__=='__main__':
    a = [10,20,30,40,50,60,130,270,380,490,5100,12010]
    print(findval(270,a))
