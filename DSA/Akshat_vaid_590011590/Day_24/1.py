class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def build_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

def print_linked_list(head):
    current = head
    while current:
        print(current.val, end=" -> " if current.next else "")
        current = current.next
    print()

def reverse_linked_list(head):
    prev = None
    curr = head
    while curr:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next
    return prev

values = [1, 2, 3, 4]
head = build_linked_list(values)
print("Original linked list:")
print_linked_list(head)
reversed_head = reverse_linked_list(head)
print("Reversed linked list:")
print_linked_list(reversed_head)
