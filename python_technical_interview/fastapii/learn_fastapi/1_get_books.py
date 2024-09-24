from fastapi import FastAPI
from pydantic import BaseModel

class Book(BaseModel):
    author: str
    title: str
    year: int

books = [
    Book(author="Homer", title="Illiad", year=-700),
    Book(author="Plato", title="Republic", year=-300)
    ]

app = FastAPI()


@app.get('/books')
def get_books() -> list[Book]:
    return books