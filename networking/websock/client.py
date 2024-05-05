import asyncio
import websockets

async def test():
    async with websockets.connect("ws://localhost:9494") as websocket:
        message = "My name is Alex"
        await websocket.send(message)
        print(f"Client sent {message}...")
        response = await websocket.recv()
        print(f"Client received {response}")

asyncio.get_event_loop().run_until_complete(test())