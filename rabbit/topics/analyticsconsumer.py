import time
import pika
from pika.exchange_type import ExchangeType

def handle_message(ch, meth, prop, body):
    time.sleep(1)
    print(f"Analytics received message: {body}")
    ch.basic_ack(delivery_tag=meth.delivery_tag)

# establish connection
conn_params = pika.ConnectionParameters('localhost')
connection = pika.BlockingConnection(conn_params)
# create a channel
channel = connection.channel()
# create an exchange
channel.exchange_declare(exchange='routing', exchange_type=ExchangeType.direct)
# create a queue
queue = channel.queue_declare(queue='', exclusive=True)
# bind queue to exchange
channel.queue_bind(queue=queue.method.queue, exchange='routing', routing_key='analyticsonly')


channel.basic_consume(queue='', on_message_callback=handle_message)
channel.start_consuming()