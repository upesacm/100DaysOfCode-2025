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

# Delete Middle of Linked List
def delete_middle_node(head):
    if not head or not head.next:
        return None

    slow = head
    fast = head
    prev = None

    while fast and fast.next:
        fast = fast.next.next
        prev = slow
        slow = slow.next

    if prev:
        prev.next = slow.next
    return head

def print_list(head):
    current = head
    while current:
        print(current.data, end=" -> " if current.next else "\n")
        current = current.next

# Sample Usage:
list = LinkedList()
for val in [1, 2, 3, 4, 5]:
    list.append(val)
print("Original list:")
print_list(list.head)
head3 = delete_middle_node(list.head)
print("After deleting middle:")
print_list(head3)
