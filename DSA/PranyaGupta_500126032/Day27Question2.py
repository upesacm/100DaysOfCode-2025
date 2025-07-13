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
    def reverse(self, head):
        
        current = self.head
        temp = None
        while current:
            temp = current.prev
            current.prev = current.next
            current.next = temp
            current = current.prev
        self.head = temp.prev    
        self.printlist(self.head)   
   


def main():
    user_input = input("Enter elements of the linked list (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    l = LinkedList()
    for num in arr:
        l.add(num)
    l.reverse(l.head)
if __name__ == "__main__":
    main()