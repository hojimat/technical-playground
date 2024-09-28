from pydantic import BaseModel


class ItemBase(BaseModel):
    title: str
    description: str | None = None

class ItemCreate(ItemBase):
    pass

class Item(ItemBase):
    id_: int
    owner_id: int

    model_config = {
            'from_attributes': True
            }



class UserBase(BaseModel):
    email: str

class UserCreate(UserBase):
    password: str

class User(UserBase):
    id_: int
    is_active: bool
    items: list[Item] = []

    model_config = {
            'from_attributes': True
            }
