class Node:
    def __init__(self,val):
        self.left = None
        self.right = None
        self.val = val
        

class Tree:
    def __init__(self):
        self.root = None

    def insert(self, val):
        if self.root is None:
            self.root = Node(val)
        else:
            self._add(val, self.root)

    def _add(self, val, node):
        if val == node.val:
            return
        elif val < node.val:
            if node.left is None:
                node.left = Node(val)
            else:
                self._add(val, node.left)
        else:
            return self._add(val, node.val.right)



































class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def printInorder(root):
    if root:
        printInorder(root.left)
        print(root.val, end=" ")
        printInorder(root.right)

def print2d(root, level=0):
    if root:
        print2d(root.left, level+1)
        print(' '*4*level + '->' + str(root.val))
        print2d(root.right, level+1)

def search(root,key):
    if root is None or root.val==key:
        print(root)
        print(root.val)
        return root

    if root.val < key:
        return search(root.right, key)

    return search(root.left, key)

def insert(root,key):
    if root is None:
        return Node(key)
    else:
        if root.val == key:
            return root
        elif root.val < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root

if __name__=="__main__":
    first = Node(9)
    first.left = Node(4)
    first.right = Node(13)
    first.left.left = Node(3)
    first.left.right = Node(12)
    first.right.left = Node(11)
    first.right.right = Node(17)

    a = Node(9)
    a = insert(a,4)
    a = insert(a,13)
    a = insert(a,3)
    a = insert(a,12)
    a = insert(a,11)
    a = insert(a,17)

    print2d(first)
    print('-------------')
    print2d(a)
