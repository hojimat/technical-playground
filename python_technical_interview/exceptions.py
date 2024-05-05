class CodeBeamerBaseException(Exception):
    def __init__(self, code, msg):
        super().__init__(msg, code)
        self.code = code
        self.msg = msg

    def __str__(self):
        return 'Pybeamer HTTP Error %s: %s' % (self.code, self.msg)


    # since URLError specifies a .reason attribute, HTTPError should also
    #  provide this attribute. See issue13211 for discussion.
    @property
    def reason(self):
        return self.msg


class UnauthorizedException(CodeBeamerBaseException):
    def __init__(self, msg):
        super(UnauthorizedException, self).__init__(code=401, msg=msg)
        self.message = msg


class ConnectionException(CodeBeamerBaseException):
    def __init__(self):
        super(ConnectionException, self).__init__(code=0, msg="No Connection")


class NotFoundException(CodeBeamerBaseException):
    def __init__(self, msg):
        super(NotFoundException, self).__init__(code=404, msg=msg)


class UnsupportedMediaTypeException(CodeBeamerBaseException):
    def __init__(self, msg):
        super(UnsupportedMediaTypeException, self).__init__(code=415, msg=msg)


class BadRequestException(CodeBeamerBaseException):
    def __init__(self, msg):
        super(BadRequestException, self).__init__(code=400, msg=msg)


class NonJsonException(CodeBeamerBaseException):

    def __init__(self):
        super(NonJsonException, self).__init__(code=1, msg="Got non json type document")


class ForbiddenException(CodeBeamerBaseException):
    def __init__(self, msg):
        super(ForbiddenException, self).__init__(code=403, msg=msg)


class InternalServerException(CodeBeamerBaseException):
    def __init__(self, msg):
        super(InternalServerException, self).__init__(code=500, msg=msg)


class ServerResponseException(CodeBeamerBaseException):
    def __init__(self, msg):
        super(ServerResponseException, self).__init__(code=550, msg=msg)


class UnableReachException(CodeBeamerBaseException):
    def __init__(self):
        super(UnableReachException, self).__init__(code=3, msg="Unable to reach the server")


class TooManyRequestException(CodeBeamerBaseException):
    def __init__(self, msg):
        super(TooManyRequestException, self).__init__(code=429, msg=msg)




if __name__=='__main__':
    raise CodeBeamerBaseException(401,'dfd')