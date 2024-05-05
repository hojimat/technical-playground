# Linked Lists:

class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def printList(self):
        temp = self.head
        while(temp):
            print(temp.data, end=" ")
            temp = temp.next

    def push(self,newdata):
        temp = self.head
        self.head = Node(newdata)
        self.head.next = temp

    def insertAfter(self, prevnode, newdata):
        if prevnode is None:
            print("the previous node does not exist")
            return
        newnode = Node(newdata)
        newnode.next = prevnode.next
        prevnode.next = newnode

    def append(self, newdata):
        newnode = Node(newdata)
        if self.head is None:
            self.head = newnode
            return
        last = self.head
        while(last.next):
            last = last.next
        last.next = newnode

if __name__=='__main__':
    llist = LinkedList()

    llist.head = Node(1)
    second = Node(2)
    third = Node(3)

    llist.head.next = second
    second.next = third

    llist.push(1034)
    

    llist.insertAfter(second, 431)
    llist.printList()

    llist.append(44444)
    llist.printList()
