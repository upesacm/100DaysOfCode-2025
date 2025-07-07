class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def countOccurrences(head, key):
    count = 0
    current = head
    while current:
        if current.val == key:
            count += 1
        current = current.next
    return count

def create_linked_list(values):
    head = ListNode(values[0])
    current = head
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

list1 = create_linked_list([1, 2, 1, 2, 1, 3, 1])
print(countOccurrences(list1, 1))

list2 = create_linked_list([1, 2, 1, 2, 1])
print(countOccurrences(list2, 3))
