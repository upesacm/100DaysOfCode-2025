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
    def kthelement(self, head, k):
        length = 0
        current = self.head
        while current:
            current= current.next
            length+=1
        current = head    
        if k>length:
            return -1
        i=1
        current = self.head
        for _ in range(length-k+1):
            current = current.next
        return current.data    


def main():
    user_input = input("Enter elements of the linked list (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    k = int(input("Enter k: "))
    l = LinkedList()
    for n in arr:
        l.add(n)
    result = l.kthelement(l.head, k)
    print(result)
if __name__ == "__main__":
    main()