from typing import Annotated
from fastapi import FastAPI, Depends, HTTPException
from sqlalchemy.orm import Session

from . import crud, models, schemas
from .database import engine, SessionLocal


models.Base.metadata.create_all(bind=engine)
app = FastAPI()


# Dependency
def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()



# Path operations

@app.post('/users/', response_model=schemas.User)
def create_user(db: Annotated[Session, Depends(get_db)], user: schemas.UserCreate):
    db_user = crud.get_user_by_email(db, email=user.email)

    if db_user:
        return HTTPException(400, detail="Email already registered")

    return crud.create_user(db, user)


@app.get('/users/', response_model=list[schemas.User])
def read_users(db: Annotated[Session, Depends(get_db)], skip: int = 0, limit: int = 100):
    db_users = crud.get_users(db, skip, limit)
    
    return db_users


@app.get('/users/{user_id}', response_model=schemas.User)
def read_user(db: Annotated[Session, Depends(get_db)], user_id: int):
    db_user = crud.get_user(db, user_id)

    if db_user is None:
        raise HTTPException(404, detail="User not found")

    return db_user


@app.post('/users/{user_id}/items/', response_model=schemas.Item)
def create_item_for_user(
        db: Annotated[Session, Depends(get_db)], user_id: int, item: schemas.ItemCreate):
    
    return crud.create_user_item(db, item, user_id)


@app.get('/items/', response_model=list[schemas.Item])
def read_items(db: Annotated[Session, Depends(get_db)], skip: int = 0, limit: int = 100):
    db_items = crud.get_items(db, skip, limit)

    return db_items
