import pika
from time import sleep

from pika.exchange_type import ExchangeType

# connect to RabbitMQ via AMQP
conn_params = pika.ConnectionParameters('localhost')
# open connection
connection = pika.BlockingConnection(conn_params)
# create a channel for the connection
channel = connection.channel()
# declare an exchange
channel.exchange_declare(exchange='pubsub', exchange_type=ExchangeType.fanout)
# declare a queue with random unique name
queue = channel.queue_declare(queue='', exclusive=True)

channel.queue_bind(exchange='pubsub', queue=queue.method.queue)



def process_callback(ch, meth, prop, body):
    sleep(1)
    print(f"Consumer A received message: {body}")
    ch.basic_ack(delivery_tag=meth.delivery_tag)


# Consume a message
channel.basic_consume(queue=queue.method.queue, on_message_callback=process_callback)


print("Consumer A started consuming")

channel.start_consuming()
