class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def printLinkedList(head):
    current = head
    while current:
        print(current.val, end=' ')
        current = current.next
    print()

def create_linked_list(values):
    head = ListNode(values[0])
    current = head
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

list1 = create_linked_list([1, 2])
printLinkedList(list1)

list2 = create_linked_list([49, 10, 30])
printLinkedList(list2)
