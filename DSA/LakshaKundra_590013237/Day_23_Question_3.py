class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

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

def create_linked_list(arr):
    if not arr:
        return None
    head = Node(arr[0])
    temp = head
    for val in arr[1:]:
        temp.next = Node(val)
        temp = temp.next
    return head

def print_linked_list(head):
    res = []
    while head:
        res.append(str(head.data))
        head = head.next
    print("->".join(res))

head1 = create_linked_list([1,2,3,4,5])
head1 = delete_middle(head1)
print_linked_list(head1)  # Output: 1->2->4->5

head2 = create_linked_list([2,4,6,7,5,1])
head2 = delete_middle(head2)
print_linked_list(head2)  # Output: 2->4->6->5->1
