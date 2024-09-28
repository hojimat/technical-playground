from typing import Annotated, Any
from fastapi import FastAPI, Path, Query, Body
from pydantic import BaseModel, Field

class Book(BaseModel):
    author: str
    title: str
    year: int = Field(gt=-3000, lt=2100)

books = {
    12: Book(author="Homer", title="Illiad", year=-700),
    13: Book(author="Plato", title="Republic", year=-300)
}

app = FastAPI()


@app.get('/books')
def get_books():
    return books

@app.put('/books/{book_id}')
def put_book(
        book_id: Annotated[int, Path(ge=0, le=1000)],
        book: Book,
        q: str | None = None):

    results: dict[str, Any] = {"book_id": book_id}
    
    if q:
        print('hi')
        results.update({"q": q})
    
    books[book_id] = book         

    results.update({"book": book})

    return results

