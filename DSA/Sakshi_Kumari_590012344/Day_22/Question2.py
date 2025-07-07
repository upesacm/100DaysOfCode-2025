Your task: Count occurrences of a specific key in a linked list using efficient traversal and 
counting methods.

class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

def count_occurrences(head, key):
    count = 0
    current = head

    while current:
        if current.value == key:
            count += 1
        current = current.next

    return count
