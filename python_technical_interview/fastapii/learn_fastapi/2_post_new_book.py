from enum import Enum
from fastapi import FastAPI
from pydantic import BaseModel

class Genre(str, Enum):
    HORROR = "horror"
    COMEDY = "comedy"
    EPIC   = "epic"

class Book(BaseModel):
    title: str
    author: str
    year: int
    genre: Genre


books: list[Book] = [
    Book(title="Illiad", author="Homer", year=750, genre=Genre.EPIC),
    Book(title="Birds", author="Eristophanes", year=850, genre=Genre.COMEDY),
    Book(title="Shining", author="Stephen King", year=1970, genre=Genre.HORROR),
]


app = FastAPI()


@app.get('/books/')
async def get_books() -> dict[str, list[Book]]:
    return {"response": books}

@app.post('/books/')
async def post_book(book: Book) -> dict[str, str]:
    books.append(book)
    return {"response": f"successfully added a book with {book.title=}"}