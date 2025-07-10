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

def delete_n_after_m(head, m, n):
    current = head
    while current:
        for _ in range(1, m):
            if current is None:
                return head
            current = current.next
        if current is None:
            return head
        temp = current.next
        for _ in range(n):
            if temp is None:
                break
            temp = temp.next
        current.next = temp
        current = temp
    return head

values = [9, 1, 3, 5, 9, 4, 10, 1]
m = 2
n = 1
head = build_linked_list(values)
print("Original linked list:")
print_linked_list(head)
head = delete_n_after_m(head, m, n)
print("Linked list after deleting N after M:")
print_linked_list(head)
