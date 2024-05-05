from django.db import models

class Teacher(models.Model):
    name = models.CharField(max_length=200)

class Student(models.Model):
    name = models.CharField(max_length=200)
    age = models.PositiveIntegerField()

class Course(models.Model):
    subject = models.CharField(max_length=200)
    teacher = models.ForeignKey(Teacher, on_delete=models.RESTRICT, related_name="courses")
    
    
    




