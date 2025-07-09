
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


def delete_middle(head):
    if not head or not head.next:
        return None  

    slow = head
    fast = head
    prev = None

    while fast and fast.next:
        fast = fast.next.next
        prev = slow
        slow = slow.next

   
    prev.next = slow.next  
    return head

values = [1, 2, 3, 4, 5]
head = build_linked_list(values)

print("Original Linked List:")
print_linked_list(head)

head = delete_middle(head)

print("After Deleting Middle Node:")
print_linked_list(head)
