import time
import pika
from pika.exchange_type import ExchangeType

# establish connection
conn_params = pika.ConnectionParameters('localhost')
connection = pika.BlockingConnection(conn_params)
# create a channel
channel = connection.channel()
# create an exchange
channel.exchange_declare(exchange='routing', exchange_type=ExchangeType.direct)


# create a message
message = "This message needs to be routed"
# publish to exchange
channel.basic_publish(exchange='routing', routing_key='paymentsonly', body=message)
print(f"sent message {message}")

# close connection
connection.close()