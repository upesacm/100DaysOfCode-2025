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

# Remove Duplicates from a Sorted Linked List
def remove_duplicates_sorted_list(head):
    current = head
    while current and current.next:
        if current.data == current.next.data:
            current.next = current.next.next
        else:
            current = current.next
    return head

def print_list(head):
    current = head
    while current:
        print(current.data, end=" -> " if current.next else "\n")
        current = current.next

# Sample Usage:
ll2 = LinkedList()
for val in [2, 2, 4, 5]:
    ll2.append(val)
print("Original list:")
print_list(ll2.head)
head2 = remove_duplicates_sorted_list(ll2.head)
print("After removing duplicates:")
print_list(head2)