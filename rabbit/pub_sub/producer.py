import pika
from time import sleep

from pika.exchange_type import ExchangeType


# connect to RabbitMQ via AMQP
conn_params = pika.ConnectionParameters('localhost')
# open connection
connection = pika.BlockingConnection(conn_params)
# create a channel for the connection
channel = connection.channel()

# no need to declare a queue in the producer (don't care about consumers)
# declare exchange
channel.exchange_declare(exchange='pubsub', exchange_type=ExchangeType.fanout )

# send a message
i=0
while i<100:
    message = f"Hello, this is my message # {i}!"
    channel.basic_publish(exchange='pubsub', routing_key='', body=message)
    print(f"sent message: {message}")
    sleep(1)
    i+=1

connection.close()
