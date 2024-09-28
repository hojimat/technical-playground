from typing import Annotated

from fastapi import FastAPI, Depends
from fastapi.datastructures import QueryParams


app = FastAPI()


class CommonParams:
    def __init__(self, q: str | None = None, skip: int = 0, limit: int = 100) -> None:
        self.q = q
        self.skip = skip
        self.limit = limit
        

@app.get('/items')
async def get_items(commons: Annotated[CommonParams, Depends()]):
    return commons


@app.get('/books')
async def get_books(commons: Annotated[CommonParams, Depends()]):
    return commons


