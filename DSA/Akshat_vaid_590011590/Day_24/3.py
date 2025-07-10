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

def delete_at_position(head, x):
    if x == 1:
        return head.next
    current = head
    for _ in range(x - 2):
        if current is None or current.next is None:
            return head
        current = current.next
    if current.next:
        current.next = current.next.next
    return head

# Example usage
values = [1, 5, 2, 9]
x = 2
head = build_linked_list(values)
print("Original list:")
print_linked_list(head)
head = delete_at_position(head, x)
print("After deleting position", x, ":")
print_linked_list(head)
