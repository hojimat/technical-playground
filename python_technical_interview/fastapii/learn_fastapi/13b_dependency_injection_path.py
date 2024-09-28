from typing import Annotated

from fastapi import Depends, FastAPI, Header, HTTPException
from pydantic import HttpUrl

app = FastAPI()


async def verify_token(x_token: Annotated[str, Header()]):
    if x_token != "fake-secret-token":
        raise HTTPException(400, "Invalid token")

async def verify_key(x_key: Annotated[str, Header()]):
    if x_key != "fake-secret-key":
        raise HTTPException(400, "Invalid key")

    return x_key


@app.get('/items', dependencies=[Depends(verify_token), Depends(verify_key)])
async def read_items():
    return [{"item": "Foo"}, {"item": "Bar"}]
