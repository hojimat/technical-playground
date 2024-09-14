from kafka import KafkaProducer
import json


producer = KafkaProducer(
    bootstrap_servers=['localhost:29092'],
    value_serializer=lambda v: json.dumps(v).encode('utf-8')
)

for i in range(100):
    message = {'number': i}
    producer.send('mytopic', message)
    print(f"Sent: {message}")

producer.flush()
