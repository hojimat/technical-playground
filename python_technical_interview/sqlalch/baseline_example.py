from sqlalchemy import create_engine, ForeignKey, Column, String, Integer, CHAR
from sqlalchemy.orm import declarative_base, sessionmaker


Base = declarative_base()


class Person(Base):
    __tablename__ = "people"

    ssn = Column("ssn", Integer, primary_key=True)
    firstname = Column("firstname", String)
    lastname = Column("lastname", String)
    gender = Column("gender", CHAR)
    age = Column("age", Integer)

    def __init__(self, ssn, firstname, lastname, gender, age):
        self.ssn = ssn
        self.firstname = firstname
        self.lastname = lastname
        self.gender = gender
        self.age = age

    def __repr__(self):
        return f"Person({self.ssn}, {self.firstname}, {self.lastname}, {self.gender}, {self.age})"


class Thing(Base):
    __tablename__ = "things"

    tid = Column("tid", Integer, primary_key=True)
    description = Column("description", String)
    owner = Column(Integer, ForeignKey("people.ssn"))
    
    def __init__(self, tid, description, owner):
        self.tid = tid
        self.description = description
        self.owner = owner
    
    def __repr__(self):
        return f"Thing({self.tid}, {self.description}, {self.owner})"




def main():
    engine = create_engine('sqlite:///mydb.db', echo=True)
    Base.metadata.create_all(bind=engine)

    Session = sessionmaker(bind=engine)
    session = Session()

    # p1 = Person(1234, "Adam", "Smith", 'm', 29)
    # p2 = Person(1235, "Claudia", "Godin", 'f', 35)
    # p3 = Person(1236, "Milton", "Friedman", 'm', 49)

    # session.add(p1)
    # session.add(p2)
    # session.add(p3)
    # session.commit()


    # t1 = Thing(1, "Car", p1.ssn)
    # t2 = Thing(2, "House", p1.ssn)
    # t3 = Thing(3, "Key", p2.ssn)
    # t4 = Thing(4, "PC", p3.ssn)


    # session.add(t1)
    # session.add(t2)
    # session.add(t3)
    # session.add(t4)
    # session.commit()


    results = session.query(Person).all()
    print(results)

    results = session.query(Person).filter(Person.lastname == "Smith")
    print(list(results))

    results = session.query(Person).filter(Person.age > 30)
    print(list(results))


    results = session.query(Person).filter(Person.age > 30)
    print(list(results))


    results = session.query(Thing, Person).filter(Thing.owner == Person.ssn).filter(Person.age > 30)
    print(list(results))
 

    


if __name__=='__main__':
    main()