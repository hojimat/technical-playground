from fastapi import FastAPI, Query
from typing import Annotated

app = FastAPI()


@app.get('/books')
def query_books(name: Annotated[str, Query(max_length=5)]) -> dict[str, str]:
    return {"response": f"Successfully added a book with {name=}"}