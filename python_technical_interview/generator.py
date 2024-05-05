def naive_firstn(n):
    nums = []

    num = 0
    while num<n:
        nums.append(num)
        num += 1
    return nums

class gen_firstn():
    def __init__(self,n):
        self.n = n
        self.num = 0
    def __iter__(self):
        return self
    def __next__(self):
        if self.num < self.n:
            cur, self.num = self.num, self.num+1
            return cur
        raise StopIteration()

def coolgen_firstn(n):
    num = 0
    while num < n:
        yield num
        num += 1

if __name__=="__main__":
    print(sum(coolgen_firstn(100000000)))

                          
