from fastapi import FastAPI
from time import sleep
import asyncio

app = FastAPI()


@app.get('/terrible')
async def terrible():
    print("Starting terrible process...")
    sleep(5)
    print("Terrible process finished.")
    return {"Message": "Successful"}

@app.get('/good')
def terrible():
    print("Starting terrible process...")
    sleep(5)
    print("Terrible process finished.")
    return {"Message": "Successful"}

@app.get('/perfect')
async def terrible():
    print("Starting terrible process...")
    await asyncio.sleep(5)
    print("Terrible process finished.")
    return {"Message": "Successful"}








