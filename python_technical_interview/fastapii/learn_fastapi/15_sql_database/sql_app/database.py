from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker, declarative_base


SQLALCHEMY_DATABASE_URL = 'sqlite:///./sql_app.db'


engine = create_engine(
        SQLALCHEMY_DATABASE_URL,
        connect_args={'check_same_thread': False}
        )

# its instances will be separate db sessions 
SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)

Base = declarative_base()
