class Father:
    def __init__(self):
        print("Father is created")

    def greet(self):
        print('howdy!')

class Son(Father):
    def __init__(self):
        print("Son is created")
    def greet(self):
        print('wazzup!')


dad = Father()
son = Son()

dad.greet()
son.greet()