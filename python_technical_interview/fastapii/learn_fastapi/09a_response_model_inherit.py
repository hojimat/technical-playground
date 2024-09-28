from fastapi import FastAPI
from pydantic import BaseModel, Field

class Book(BaseModel):
    title: str

class BaseUser(BaseModel):
    name: str

class UserIn(BaseUser):
    password: str

app = FastAPI()


@app.get('/booksRM', response_model=list[Book])
async def get_booksRM():
    return [{"title":"Illiad"}, {"title":"Odyssey"}]

@app.get('/books')
async def get_books() -> list[Book]:
    return [Book(title="Illiad"), Book(title="Odyssey")]

@app.post('/users')
async def create_user(user: UserIn) -> BaseUser:
    return user