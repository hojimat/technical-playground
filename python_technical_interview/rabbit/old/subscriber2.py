import pika
from pika.exchange_type import ExchangeType

def on_msg_rcv(ch, method, properties, body):
    print('Subscriber 2 received the message')

params = pika.ConnectionParameters('localhost')
connection = pika.BlockingConnection(params)

channel = connection.channel()

channel.exchange_declare(exchange='pubsub', exchange_type=ExchangeType.fanout)

queue = channel.queue_declare(queue='', exclusive=True)

channel.queue_bind(exchange='pubsub', queue=queue.method.queue)

channel.basic_consume(queue='', auto_ack=True, on_message_callback=on_msg_rcv)

channel.start_consuming()