from abc import ABC

class Object(ABC):
    def __init__(self, server):
        self._server = server
        self._name = "Object!"

    
class Project(Object):
    def __init__(self, server, name):
        super().__init__(server)
        self._name = name

class Task(Object):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self._name = "Task"

obj = Object('123')
proj = Project('123', 'hello')

print(proj)
print(proj._server)
print(proj._name)
breakpoint()
