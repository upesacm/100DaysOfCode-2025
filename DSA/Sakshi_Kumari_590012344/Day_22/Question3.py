Your task: Traverse and print all elements of a linked list in the correct order with proper 
spacing.

class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

def print_linked_list(head):
    current = head
    while current:
        print(current.value, end=' ')
        current = current.next
