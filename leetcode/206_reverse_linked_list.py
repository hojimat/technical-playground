class Node:
    def __init__(self, value, pnext):
        self.value = value
        self.pnext = pnext


class LinkedList:
    def __init__(self, head=None):
        self.head = head

    def append(self, value):
        if self.head is None:
            self.head = Node(value, None)
            return
        
        curr = self.head
        while curr.pnext:
            curr = curr.pnext
        curr.pnext = Node(value, None)

    def display(self):
        if self.head is None:
            print("The linked list is empty")
            return
        
        curr = self.head
        while curr.pnext:
            print(curr.value, end=" ")
            curr = curr.pnext
        print(curr.value)


class Solution:
    def reverseList(self, head: Node) -> Node:
        '''
        given [1,p2]
        return [6,p5]

        METHOD:
        - set pprev = None
        - go to llist.head (1,p2)
        - set curr = head  (1,p2)
        - set pnext = curr.pnext (p2)
        - set curr.pnext = pprev (None)
        - save pprev = curr (1,p2)
        - curr = pnext
        '''

        if head is None:
            print("Head is empty")
            return

        pprev = None
        curr = head
        while curr.pnext:
            pnext = curr.pnext # maybe need to copy
            curr.pnext = pprev # which is None
            pprev = curr # update pprev
            curr = pnext # go to the next
        curr.pnext = pprev
        return curr

def main():
    inputList = []
    llist = LinkedList()
    while inputList:
        val = inputList.pop(0)
        llist.append(val)
    llist.display() 
    
    mySol = Solution()
    rhead = mySol.reverseList(llist.head)
    rlist = LinkedList(rhead)
    
    rlist.display()


if __name__=="__main__":
    main()