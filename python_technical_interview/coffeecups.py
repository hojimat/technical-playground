class Developer:
    coffee_cups = 0

    def __init__(self, name):
        self.name = name
        Developer.coffee_cups += 1

    def speak(self):
        print(f"My name is {self.name} and I had {self.coffee_cups} today")

rover = Developer("Steve")
rover.speak()

spot = Developer("Bob")
spot.speak()

vdud = Developer("John")
vdud.speak()

