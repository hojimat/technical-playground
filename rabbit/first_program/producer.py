import pika
from time import sleep


# connect to RabbitMQ via AMQP
conn_params = pika.ConnectionParameters('localhost')
# open connection
connection = pika.BlockingConnection(conn_params)
# create a channel for the connection
channel = connection.channel()
# declare a queue
channel.queue_declare(queue="letterbox")


# send a message
i=0
while i<100:
    message = "Hello, this is my message!"
    channel.basic_publish(exchange='', routing_key='letterbox', body=message)
    print(f"sent message:{message}")
    sleep(0.5)
    i+=1

connection.close()
