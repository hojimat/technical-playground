class Agent:
    def __init__(self, name):
        self.name = name

class Firm:
    def __init__(self):
        self.agent = None

    def hire_agent(self, agent):
        self.agent = agent


john = Agent('john')
firm = Firm()
print(firm.agent)
firm.hire_agent(john)
print(firm.agent)
print(id(john))
print(id(firm.agent))
print(john==firm.agent)
print(john is firm.agent)

