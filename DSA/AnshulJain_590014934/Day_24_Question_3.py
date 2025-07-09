class Node:
    def __init__(self, data): self.data = data; self.next = None
class LinkedList:
    def __init__(self): self.head = None
    def append(self, data):
        if not self.head: self.head = Node(data); return
        cur = self.head
        while cur.next: cur = cur.next
        cur.next = Node(data)
    def delete_at_position(self, pos):
        if pos <= 0: return
        if pos == 1: self.head = self.head.next if self.head else None; return
        cur = self.head
        for _ in range(pos - 2):
            if not cur or not cur.next: return
            cur = cur.next
        if cur and cur.next: cur.next = cur.next.next
    def display(self):
        cur = self.head
        while cur: print(cur.data, end=" "); cur = cur.next
        print()
ll = LinkedList()
for v in input("Enter the linked list:").split(): ll.append(int(v))
ll.delete_at_position(int(input("x: ")))
ll.display()
# for example :-
#     input:- 1 2 3 4 5
#     x: 3
#     output:- 1 2 4 5