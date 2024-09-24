from fastapi import FastAPI, Path
from typing import Annotated

app = FastAPI()


@app.get('/books/{book_id}')
def get_books(book_id: Annotated[int, Path(title="The id of the request", ge=1000)]) -> dict[str,str]:
    return {"response": f"Here is the book with {book_id=}"}
