# Kth from End of Linked List
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

    def find_kth_from_end(self, k):
        first = self.head
        second = self.head

        for _ in range(k):
            if not first:
                return -1
            first = first.next

        while first:
            first = first.next
            second = second.next

        return second.data if second else -1

def print_list(head):
    current = head
    while current:
        print(current.data, end=" -> " if current.next else "\n")
        current = current.next

# Sample Usage:
ll1 = LinkedList()
for i in range(1, 10):
    ll1.append(i)
print("Kth from end:", ll1.find_kth_from_end(2)) 