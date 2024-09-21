import pika
from time import sleep

# connect to RabbitMQ via AMQP
conn_params = pika.ConnectionParameters('localhost')
# open connection
connection = pika.BlockingConnection(conn_params)
# create a channel for the connection
channel = connection.channel()
# declare a queue
channel.queue_declare(queue='letterbox')
# set prefetch=1
channel.basic_qos(prefetch_count=1)

def process_callback(ch, meth, prop, body):
    sleep(3)
    print(f"Received message: {body}")
    ch.basic_ack(delivery_tag=meth.delivery_tag)


# Consume a message
channel.basic_consume(queue='letterbox', on_message_callback=process_callback)


print("Started consuming")

channel.start_consuming()
