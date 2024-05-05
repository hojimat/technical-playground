class Server:
    def __init__(self, ip, port):
        self.ip = ip
        self.port = port
        print('Opened a session')

    def __exit__(self, exc_type, exc, tb):
        print('Closed a session')

    def __del__(self):
        print('Closed a session')


if __name__=='__main__':
    server = Server(127001, 9999)
    print('Done')
