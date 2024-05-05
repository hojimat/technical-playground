class Person:
    def __init__(self, name, job, age):
        self.name = name
        self.job = job
        self.age = age

    def __str__(self):
        return f"{self.name} the {self.job}"


class Organization:
    def __init__(self, name):
        self.name = name
        self.employees = []

    def hire(self,person):
        self.employees.append(person)


if __name__=='__main__':
    filename = __file__
    import logging
    logging.basicConfig(level=logging.NOTSET)
    
    john = Person("john", "engineer", 132)
    paul = Person("paul", "singer", 32)
    george = Person("george", "doctor", 43)
    ringo = Person("ringo", "weatherman", 23)
  #  breakpoint()
    logging.log(level=logging.WARNING, msg="All people created")

    oracle = Organization("oracle")
 #   breakpoint()
    logging.log(level=logging.WARNING, msg="Organization created")
    
    
    oracle.hire(john)
    oracle.hire(paul)
    logging.log(level=logging.WARNING, msg="All people hired")
#    breakpoint()
