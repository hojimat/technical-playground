import redis

r = redis.Redis(host='localhost', port=6379, db=0)

r.set('hiskey', 'Hello world')

value = r.get('mykey2')
print(value)
