from datetime import datetime, timedelta, timezone
from typing import Annotated

from fastapi import FastAPI, Depends, HTTPException
from fastapi.security import OAuth2PasswordBearer, OAuth2PasswordRequestForm

import jwt
from jwt.exceptions import InvalidTokenError
from passlib.context import CryptContext

from pydantic import BaseModel


SECRET_KEY = '7f9207da248e88afd09cfc991d8a9d3dc137020abdb12828aaba1d8f10ea56fa'
ALGORITHM = 'HS256'
ACCESS_TOKEN_EXPIRE_MINUTES = 30




# Database
fake_users_db = {
        "ravshan": {
            "username": "rsk",
            "email": "rsk@comp.org",
            "hashed_password": "$2a$12$LmaDJuZhgJO.hmvEDNWmv.3IPr8mbjiDXx6Byn3dG3yZvBB0.Pcda",
            "disabled": False
            },
        "sanjar": {
            "username": "skt",
            "email": "skt@comp.org",
            "hashed_password": "$2b$12$EixZaYVK1fsbw1ZfbX3OXePaWxn96p36WQoeG6Lruj3vjPGga31lW",
            "disabled": False
            }
        }





# Model definitions
class Token(BaseModel):
    access_token: str
    token_type: str

class TokenData(BaseModel):
    username: str | None = None


class User(BaseModel):
    username: str
    email: str | None = None
    disabled: bool | None = None

class UserInDB(User):
    hashed_password: str




# Security
pwd_context = CryptContext(schemes=['bcrypt'], deprecated='auto')

oauth2_scheme = OAuth2PasswordBearer(tokenUrl="token")

# Start the app
app = FastAPI()





# Helpers

def verify_password(plain_password, hashed_password):
    return pwd_context.verify(plain_password, hashed_password)


def get_password_hash(pwd: str):
    return pwd_context.hash(pwd)

def get_user_from_db(db, username: str):
    '''
    get user from database and map it into model
    '''
    if username in db:
        return UserInDB(**db[username])

def authenticate_user(db, username: str, password: str):
    user = get_user_from_db(db, username)
    if not user:
        return False
    if not verify_password(password, user.hashed_password):
        return False
    return user


def create_access_token(data: dict, expires_delta: timedelta | None = None):
    to_encode = data.copy()

    if expires_delta:
        expire = datetime.now(timezone.utc) + expires_delta
    else:
        expire = datetime.now(timezone.utc) + timedelta(minutes=15)

    to_encode.update({"exp": expire})
    encoded_jwt = jwt.encode(to_encode, SECRET_KEY, algorithm=ALGORITHM)

    return encoded_jwt




# Dependency chain
# request[username] -> /users/me -> get_current_active_user -> get_current_user -> 
# -> oauth2_scheme -> string[token] -> user[current_user] -> response[current_user]

async def get_current_user(token: Annotated[str, Depends(oauth2_scheme)]):
    CredentialsException = HTTPException(
            status_code=401,
            detail="Wrong credentials",
            headers={"WWW-Authenticate": "Bearer"}
            )
    
    try:
        payload = jwt.decode(token, SECRET_KEY, algorithms=[ALGORITHM])
        username: str = payload.get("sub")
    
        if username is None:
            raise CredentialsException
        
        token_data = TokenData(username=username)

    except InvalidTokenError:
        raise CredentialsException


    user = get_user_from_db(fake_users_db, username=token_data.username)
    if user is None:
        raise CredentialsException 
    return user

@app.get('/users/me')
async def read_users_me(current_user: Annotated[User, Depends(get_current_user)]):
    return current_user







# Dependency chain request[form_data] -> /token -> OauthRequestForm -> validated_form_data
# takes username and password
@app.post('/token')
async def login(form_data: Annotated[OAuth2PasswordRequestForm, Depends()]) -> Token:
    user = authenticate_user(fake_users_db, form_data.username, form_data.password)

    if not user:
        raise HTTPException(
                status_code=401,
                detail="incorrect username",
                headers={"WWW-Authenticate": "Bearer"}
                )

    access_token = create_access_token(
            data = {"sub": user.username},
            expires_delta=timedelta(minutes=ACCESS_TOKEN_EXPIRE_MINUTES)
            )

    return Token(access_token=access_token, token_type="bearer")



