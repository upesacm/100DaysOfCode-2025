class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

def find_kth_from_end(head, k):
    if not head or k <= 0:
        return -1

    first = head
    second = head

    for _ in range(k):
        if not first:
            return -1
        first = first.next

    while first:
        first = first.next
        second = second.next

    return second.val

def print_list(head):
    current = head
    while current:
        print(current.val, end=' ')
        current = current.next
    print()

head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)

print("Original list:")
print_list(head)

k = 2
result = find_kth_from_end(head, k)

if result != -1:
    print(f"The {k}th node from end is: {result}")
else:
    print("Invalid k or empty list")
