class Rect():
    def __init__(self,l,w):
        self.l = l
        self.w = w

    def perimeter(self):
        print(2*(self.l + self.w))
    def area(self):
        print(self.l * self.w)

class Skw():
    def __init__(self,l):
        self.l = l
    def perimeter(self):
        print(4*self.l)
    def area(self):
        print(self.l**2)

class Sq(Rect):
    def __init__(self,l):
        super().__init__(l,l)

if __name__=='__main__':
    r = Rect(4,2)
    s = Skw(4)
    t = Sq(4)
    print(type(r))
    print(type(s))
    print(type(t))

