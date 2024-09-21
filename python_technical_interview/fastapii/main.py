from enum import Enum
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel


app = FastAPI()

class Category(Enum):
    TOOLS = "complicated_name_for_tools"
    CONSUMABLES = "complicated_name_for_consumables"


class Item(BaseModel):
    name: str
    price: float
    count: int
    id_: int
    category: Category


# Placeholder for database
items = {
    0: Item(name="Hammer", price=314, count=10, id_=0, category=Category.TOOLS),
    1: Item(name="Pliers", price=100, count=4, id_=1, category=Category.TOOLS),
    2: Item(name="Nails", price=23, count=300, id_=2, category=Category.CONSUMABLES)
}


# Server
@app.get("/")
def index() -> dict[str, dict[int, Item]]:
    return {"mytems": items}


@app.get("/items/{item_id}")
def query_item_by_id(item_id: int) -> Item:
    if item_id not in items:
        raise HTTPException(status_code=404, detail=f"Item with {item_id=} does not exist")

    return items[item_id]

@app.get("/items")
def query_item_by_params(
        name: str | None = None, id_: int | None = None,
        category: Category | None = None) -> dict[str, list[Item]]:

    def check_item(item: Item) -> bool:
        return all(
            (
                name is None or item.name == name,
                id_ is None or item.id_ == id_,
                category is None or item.category == category
            )
        )

    selection = [item for item in items.values() if check_item(item)]

    return {"results": selection}


@app.post("/")
def add_new_item(item: Item) -> dict[str, Item]:
    if item.id_ in items:
        raise HTTPException(status_code=400, detail=f"Item with {item.id_=} already exists")

    items[item.id_] = item
    
    return {"added": item}


@app.delete("/items/{item_id}")
def delete_item(item_id: int) -> dict[str, str]:
    if item_id not in items:
        raise HTTPException(status_code=404, detail=f"Item with {item_id=} does not exist.")

    items.pop(item_id)

    return {"deleted": f"{item_id}"}
