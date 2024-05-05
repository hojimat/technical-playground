''' Binary Trees '''

class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val)
        inorder(root.right)


inorder(root)
