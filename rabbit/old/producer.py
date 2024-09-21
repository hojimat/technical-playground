import pika

params = pika.ConnectionParameters('localhost')
connection = pika.BlockingConnection(params)

channel = connection.channel()
channel.queue_declare(queue='letterbox')

message = 'My first message'
channel.basic_publish(exchange='', routing_key='letterbox', body=message)# use default exchange 
print("Message sent")

connection.close()