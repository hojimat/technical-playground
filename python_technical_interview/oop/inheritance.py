class Father:
    def sayhi(self):
        '''dad saying hi'''
        print("Hello, I am a father!")


class Son(Father):
    def sayhi(self):
        print("Hello, I am a son")


# Polymorphism:
def sayhello(person):
    person.sayhi()
john = Father()
jack = Son()
sayhello(john)
sayhello(jack)

# Method overloading (docstrings are inherited)
john = Father()
jack = Son()
print(help(jack.sayhi))
print(help(john.sayhi))
