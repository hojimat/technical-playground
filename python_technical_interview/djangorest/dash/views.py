from django.shortcuts import render
from rest_framework import viewsets

class MainViewSet(viewsets.ModelViewSet):
    queryset = Movie.objects.all()
    serializer = MovieSerializer

