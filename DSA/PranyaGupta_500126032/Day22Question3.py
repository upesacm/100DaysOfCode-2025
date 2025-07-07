class node:
    def __init__(self, data):
        self.next = None
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
    def printlist(self, head):
        current = self.head
        while current:
            print(current.data, end="->")
            current = current.next

def main():
    user_input = input("Enter elements of the linked list (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    l = LinkedList()
    for n in arr:
        l.add(n)
    result = l.printlist(l.head)
    print(result)
if __name__ == "__main__":
    main()