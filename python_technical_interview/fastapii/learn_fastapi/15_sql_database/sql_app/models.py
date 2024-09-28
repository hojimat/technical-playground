from enum import unique
from sqlalchemy import Column, Integer, String, Boolean, ForeignKey
from sqlalchemy.orm import relationship

from .database import Base


class User(Base):
    __tablename__ = 'users'

    id_ = Column(Integer, name='id', primary_key=True)
    email = Column(String, unique=True)
    hashed_password = Column(String)
    is_active = Column(Boolean, default=True)

    items = relationship('Item', back_populates='owner')

class Item(Base):
    __tablename__ = 'items'

    id_ = Column(Integer, name='id', primary_key=True)
    title = Column(String, index=True)
    description = Column(String, index=True)
    owner_id = Column(Integer, ForeignKey('users.id'))
    
    owner = relationship('User', back_populates='items')
