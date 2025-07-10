
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


def remove_duplicates(head):
    current = head

    while current and current.next:
        if current.val == current.next.val:
            
            current.next = current.next.next
        else:
            
            current = current.next

    return head


values = [1, 1, 2, 3, 3, 4, 4, 4, 5]
head = build_linked_list(values)

print("Original Linked List:")
print_linked_list(head)

head = remove_duplicates(head)

print("After Removing Duplicates:")
print_linked_list(head)
