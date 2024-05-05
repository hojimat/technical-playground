class Teacher:
    def __init__(self):
        self.students = {}


class Student:
    def __init__(self, name):
        self.name = name


a = Teacher()
Teacher.students = {'ravhsan': Student("ravshan"), 'nazi': Student("nazi")}