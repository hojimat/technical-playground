'''
Method resolution order

Python uses depth-first search with first argument.

In diamond inheritance:
    A -> (B and C) -> D the order is: D, B, A, C
    A -> (C and B) -> D the order is: D, C, A, B

'''
class A:
    def rk(self):
        print(" In class A")

class B(A):
    def rk(self):
        print(" In class B")

class C(A):
    def rk(self):
        print(" In class C")

class D(B,C):
    def rk(self):
        print(" In class D")

r = D()
r.rk()
