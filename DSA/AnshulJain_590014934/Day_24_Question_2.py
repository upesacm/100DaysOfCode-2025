class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
class LinkedList:
    def __init__(self):
        self.head = None
    def append(self, data):
        current = self.head
        if not current:
            self.head = Node(data)
            return
        while current.next:
            current = current.next
        current.next = Node(data)
    def delete_nodes(self, m, n):
        cur = self.head
        while cur:
            for _ in range(m - 1):
                if not cur: return
                cur = cur.next
            if not cur: break
            temp = cur.next
            for _ in range(n):
                if not temp: break
                temp = temp.next
            cur.next = temp
            cur = temp
    def display(self):
        cur = self.head
        while cur:
            print(cur.data, end=" ")
            cur = cur.next
        print()
ll = LinkedList()
for v in input("Enter The linked list:").split(): ll.append(int(v))# taking input from the user
m, n = int(input("m:")), int(input("n:"))
ll.delete_nodes(m, n)
ll.display()
# for example :-
#     input:- 1 2 3 4 5 6 7
#     m: 2 , n: 3
#    output:- 1 2 6 7  