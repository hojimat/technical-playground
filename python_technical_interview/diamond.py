# Diamond problem

class M1:
    def m(self):
        print("I am in class 1")

class M2(M1):
    def m(self):
        print("I am in class 2")

class M3(M1):
    def m(self):
        print("I am in class 3")

class M4(M2,M3):
    def m(self):
        #print("I am in class 4")
        super().m()

if __name__=='__main__':
    a = M4()
    a.m()
