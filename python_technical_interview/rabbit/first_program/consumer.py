import pika

# connect to RabbitMQ via AMQP
conn_params = pika.ConnectionParameters('localhost')
# open connection
connection = pika.BlockingConnection(conn_params)
# create a channel for the connection
channel = connection.channel()
# declare a queue
channel.queue_declare(queue='letterbox')


# Consume a message
channel.basic_consume(
    queue='letterbox',
    auto_ack=True,
    on_message_callback=lambda ch,meth,prop,body: print(f"received {body}"))


print("Started consuming")

channel.start_consuming()