from fastapi import FastAPI, Depends, HTTPException


app = FastAPI()


def fake_verify_token(token: str):
    if token != 'secret-token':
        raise HTTPException(401, "Invalid token")
    return {'username': 'Ravshan'}

@app.get('/items')
async def read_items(user: dict = Depends(fake_verify_token)):
    return {'user': user, 'items': ['a','b','c']}



@app.get('/profile')
async def read_profile(user: dict = Depends(fake_verify_token)):
    return {'user': user, 'profile': {'age': 32}}