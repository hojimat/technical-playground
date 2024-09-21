def myfunc():
    try:
        print('tried a function')
        return 404
    except:
        print('got an error')
    else:
        print('didnt get an error')
    finally:
        print('anyway, closing this thing')


print(myfunc())