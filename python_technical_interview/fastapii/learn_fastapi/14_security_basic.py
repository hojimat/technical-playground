from typing import Annotated

from fastapi import FastAPI, Depends, HTTPException
from fastapi.security import OAuth2PasswordBearer, OAuth2PasswordRequestForm

from pydantic import BaseModel

# Start the app
app = FastAPI()




# Database
fake_users_db = {
        "ravshan": {
            "username": "rsk",
            "email": "rsk@comp.org",
            "hashed_password": "hashed_mypass",
            "disabled": False
            },
        "sanjar": {
            "username": "skt",
            "email": "skt@comp.org",
            "hashed_password": "hashed_hispass",
            "disabled": False
            }
        }





# User Model definition
class User(BaseModel):
    username: str
    email: str | None = None
    disabled: bool | None = None

class UserInDB(User):
    hashed_password: str




# Helpers
def get_user_from_db(db, username: str):
    '''
    get user from database and map it into model
    '''
    if username in db:
        return UserInDB(**db[username])

def decode_token(token):
    '''
    v0.1 thin wrapper; no security at all
    '''
    user = get_user_from_db(fake_users_db, token)
    return user

def hash_password(pwd: str):
    return "hashed_" + pwd





# Dependency chain
# request[username] -> /users/me -> get_current_active_user -> get_current_user -> 
# -> oauth2_scheme -> string[token] -> user[current_user] -> response[current_user]
oauth2_scheme = OAuth2PasswordBearer(tokenUrl="token")

async def get_current_user(token: Annotated[str, Depends(oauth2_scheme)]):
    user = decode_token(token)
    if not user:
        raise HTTPException(401, detail="invalid username", headers={"WWW-Authenticate": "Bearer"})
    return user

async def get_current_active_user(current_user: Annotated[User, Depends(get_current_user)]):
    if current_user.disabled:
        raise HTTPException(400, detail="inactive user")

@app.get('/users/me')
async def read_users_me(current_user: Annotated[User, Depends(get_current_active_user)]):
    return current_user







# Dependency chain request[form_data] -> /token -> OauthRequestForm -> validated_form_data
# takes username and password
@app.post('/token')
async def login(form_data: Annotated[OAuth2PasswordRequestForm, Depends()]):
    user_dict = fake_users_db.get(form_data.username)
    if not user_dict:
        raise HTTPException(400, detail="incorrect username")
    user = UserInDB(**user_dict)
    hashed_password = hash_password(form_data.password)
    if hashed_password != user.hashed_password:
        raise HTTPException(400, detail="incorrect password")

    return {"access_token": user.username, "token_type": "bearer"}



