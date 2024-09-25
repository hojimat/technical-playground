from fastapi import FastAPI
from pydantic import BaseModel, Field

class Book(BaseModel):
    title: str

class UserIn(BaseModel):
    name: str
    password: str

class UserOut(BaseModel):
    name:str

app = FastAPI()


@app.get('/booksRM', response_model=list[Book])
async def get_booksRM():
    return [{"title":"Illiad"}, {"title":"Odyssey"}]

@app.get('/books')
async def get_books() -> list[Book]:
    return [Book(title="Illiad"), Book(title="Odyssey")]

@app.post('/users', response_model=UserOut)
async def create_user(user: UserIn):
    return user