from kafka import KafkaConsumer
import json

consumer = KafkaConsumer(
    'mytopic',
    bootstrap_servers=['localhost:29092'],
    auto_offset_reset='earliest',
    group_id='mygroup',
    value_deserializer=lambda x: json.loads(x.decode('utf-8'))
)


for message in consumer:
    print(f"Received: {message.value}")