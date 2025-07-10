# Find the middle node of a linked list using efficient traversal techniques without multiple passes.
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

def find_middle(head):
    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    return slow.value

def create_linked_list(values):
    if not values:
        return None

    head = Node(values[0])
    current = head
    for val in values[1:]:
        current.next = Node(val)
        current = current.next
    return head

input_str = raw_input("Enter the linked list elements separated by spaces: ")
values = map(int, input_str.strip().split())

head = create_linked_list(values)
print "Middle node:", find_middle(head)
