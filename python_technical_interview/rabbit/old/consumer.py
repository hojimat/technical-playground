import pika

def on_msg_rcv(ch, method, property, body):
    print('Received message')

params = pika.ConnectionParameters('localhost')
connection = pika.BlockingConnection(params)

channel = connection.channel()

channel.queue_declare(queue='letterbox')

channel.basic_consume(queue='letterbox', auto_ack=True, on_message_callback=on_msg_rcv)

print('Started consuming...')
channel.start_consuming()