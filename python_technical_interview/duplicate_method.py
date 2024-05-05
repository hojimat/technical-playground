class Foo:
    def bar(self, x, y):
        print(x,y)
    def bar(self, x):
        print(x)

if __name__=='__main__':
    Foo().bar(12,21)
