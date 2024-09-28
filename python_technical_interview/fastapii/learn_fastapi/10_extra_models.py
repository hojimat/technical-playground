from fastapi import FastAPI
from pydantic import BaseModel, EmailStr

app = FastAPI()

class User(BaseModel):
    username: str
    email: EmailStr


class UserIn(User):
    password: str

class UserOut(User):
    pass

class UserInDB(User):
    hashed_password: str


def hasher(pwd: str) -> str:
    return f"hashed_{pwd}"

def save_user(user_in: UserIn) -> UserInDB:
    hpwd = hasher(user_in.password)
    user_in_db = UserInDB(**user_in.model_dump(), hashed_password=hpwd)
    return user_in_db


@app.post('/user/', response_model=UserOut)
async def create_user(user_in: UserIn):
    user_saved = save_user(user_in)
    return user_saved
