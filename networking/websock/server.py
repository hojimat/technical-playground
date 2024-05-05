import asyncio
import websockets


async def handler(websocket, path):
    data = await websocket.recv()
    print(f"Server received {data}")
    reply = f"Message: I have received your {data}"
    await websocket.send(reply)

print("setting up...")
start_server = websockets.serve(handler, "localhost", 9494)

asyncio.get_event_loop().run_until_complete(start_server)
asyncio.get_event_loop().run_forever()