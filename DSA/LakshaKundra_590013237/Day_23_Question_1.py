class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def kth_from_end(head, k):
    fast = slow = head
    for _ in range(k):
        if not fast:
            return -1
        fast = fast.next
    while fast:
        fast = fast.next
        slow = slow.next
    return slow.data if slow else -1

def create_linked_list(arr):
    if not arr:
        return None
    head = Node(arr[0])
    current = head
    for val in arr[1:]:
        current.next = Node(val)
        current = current.next
    return head

head1 = create_linked_list([1,2,3,4,5,6,7,8,9])
print(kth_from_end(head1, 2))  # Output: 8

head2 = create_linked_list([10,5,100,5])
print(kth_from_end(head2, 5))  # Output: -1
