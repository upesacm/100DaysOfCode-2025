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
    def mid(self, head):
        len = 0
        current = self.head
        while current:
            current= current.next
            len+=1
        current = head    
        for i in range(len//2):
            current = current.next
        return current.data    

def main():
    user_input = input("Enter elements of the linked list (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    l = LinkedList()
    for n in arr:
        l.add(n)
    result = l.mid(l.head)
    print(result)
if __name__ == "__main__":
    main()