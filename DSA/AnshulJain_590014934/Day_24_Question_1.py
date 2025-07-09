class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
class LinkedList:
    def __init__(self):
        self.head = None
    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node
    def reverse(self):
        prev = None
        current = self.head
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self.head = prev
    def display(self):
        current = self.head
        while current:
            print(current.data, end=" ")
            current = current.next
        print()
values = input("Enter the linked list:").split() # taking input from the user 
linked_list = LinkedList()
for val in values:
    linked_list.append(int(val))
linked_list.reverse()
linked_list.display()
# for example :-
#     input:- 1 2 4 5 6
#     output:- 6 5 4 2 1