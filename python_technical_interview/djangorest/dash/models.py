from django.db import models

class Movie(models.Model):
    name = models.CharField(max_length=200)
    year = models.PositiveIntegerField()
    director = models.CharField(max_length=200)
    genre = models.CharField(max_length=200)
