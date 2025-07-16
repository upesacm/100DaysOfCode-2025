class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def count_occurrences(head, key):
    count = 0
    current = head
    while current:
        if current.data == key:
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

values = list(map(int, input("Enter linked list values separated by space: ").split()))
key = int(input("Enter the key to count: "))
head = create_linked_list(values)
print(count_occurrences(head, key))
