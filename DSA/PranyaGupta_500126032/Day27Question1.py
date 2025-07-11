class node:
    def __init__(self, data):
        self.next = None
        self.prev = None
        self.data = data
class LinkedList:
    def __init__(self):
        self.head = None
    def add(self, data):
        new_node = node(data)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node
        new_node.prev = current
    def printlist(self, head):
        current = head
        while current:
            print(current.data, end=" ")
            current = current.next   
    def deletenode(self, head, pos):
        if pos == 1:
            self.head = self.head.next
            self.head.prev = None
            self.printlist(self.head)
        i = 1
        current = self.head
        prevn = None
        while  i<pos and current.next:
            prevn = current
            current = current.next
            i+=1
        if not current.next:
            return    
        current.prev = None
        prevn.next = current.next
        current.next.prev = prevn
        self.printlist(head)
       


def main():
    user_input = input("Enter elements of the linked list (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    pos = int(input("Enter pos: "))
    l = LinkedList()
    for num in arr:
        l.add(num)
    l.deletenode(l.head, pos)
if __name__ == "__main__":
    main()