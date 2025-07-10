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
            print(current.data, end=" ")
            current = current.next   
    def deletenode(self, head, pos):
        if pos == 1:
            self.head = self.head.next
            return
        i = 1
        current = self.head
        while  i<pos-1 and current.next:
            current = current.next
            i+=1
        if not current.next:
            return    
        current.next = current.next.next
    def deletemn(self,head, m, n):
        curr = self.head
        l=0
        while curr:
            curr= curr.next
            l+=1
        for i in range(m+n,l,n):
            self.deletenode(self.head, i)
        self.printlist(self.head)     


def main():
    user_input = input("Enter elements of the linked list (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    m = int(input("Enter n: "))
    n = int(input("Enter m: "))
    l = LinkedList()
    for num in arr:
        l.add(num)
    l.deletemn(l.head, m,n)
if __name__ == "__main__":
    main()