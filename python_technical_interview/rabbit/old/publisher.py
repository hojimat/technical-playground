import pika
from pika.exchange_type import ExchangeType

params = pika.ConnectionParameters('localhost')
connection = pika.BlockingConnection(params)

channel = connection.channel()
# do not declare the queue - producer does not care

channel.exchange_declare(exchange='pubsub', exchange_type=ExchangeType.fanout)

message = 'Hello, I am broadcasting this message!'
channel.basic_publish(exchange='pubsub', routing_key='', body=message)
print('message sent.')

connection.close()