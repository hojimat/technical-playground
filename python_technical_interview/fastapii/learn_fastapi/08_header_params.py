from typing import Annotated
from fastapi import FastAPI, Header


app = FastAPI()


@app.get('/items')
def get_items(user_agent: Annotated[str | None, Header()] = None):
    return {"User-Agent": user_agent}
