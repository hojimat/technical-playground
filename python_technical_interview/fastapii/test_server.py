import requests
import json

print('----------------------')
print('Get all items')
responses = requests.get("http://127.0.0.1:8000").json()
print(responses)


print('----------------------')
print('Get first item by address')
responses = requests.get("http://127.0.0.1:8000/items/1").json()
print(responses)


print('----------------------')
print('Get first item by query name')
responses = requests.get("http://127.0.0.1:8000/items?name=Pliers").json()
print(responses)

print('----------------------')
print('Add a new item')
my_json = {'name': 'Axe', 'price': 314, 'count': 10, 'id_': 10, 'category': 'complicated_name_for_tools'}
responses = requests.post("http://127.0.0.1:8000/", json=my_json)
print(responses)

print('----------------------')
print('Get all items')
responses = requests.get("http://127.0.0.1:8000").json()
print(responses)

print('----------------------')
print('Delete id=10')
responses = requests.delete("http://127.0.0.1:8000/items/10").json()
print(responses)

print('----------------------')
print('Delete id=123')
responses = requests.delete("http://127.0.0.1:8000/items/123").json()
print(responses)


print('----------------------')
print('Get all items')
responses = requests.get("http://127.0.0.1:8000").json()
print(responses)
