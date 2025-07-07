class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def middleNode(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow

def create_linked_list(values):
    head = ListNode(values[0])
    current = head
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

list1 = create_linked_list([1, 2, 3, 4, 5])
middle1 = middleNode(list1)
print(middle1.val)

list2 = create_linked_list([2, 4, 6, 7, 5, 1])
middle2 = middleNode(list2)
print(middle2.val)
