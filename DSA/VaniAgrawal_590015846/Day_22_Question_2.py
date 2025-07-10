# Count occurrences of a specific key in a linked list using efficient traversal and counting methods.
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

def count_frequency(head, key):
    count = 0
    current = head
    while current:
        if current.value == key:
            count += 1
        current = current.next
    return count

def create_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for val in values[1:]:
        current.next = Node(val)
        current = current.next
    return head

input_str = raw_input("Enter linked list elements (space-separated): ")
key_input = raw_input("Enter the key to search for: ")

values = map(int, input_str.strip().split())
key = int(key_input.strip())

head = create_linked_list(values)
result = count_frequency(head, key)

print "Frequency of", key, "is:", result
