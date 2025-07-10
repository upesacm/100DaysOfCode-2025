class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def deleteNode(head, x):
    if x == 1:
        return head.next
    current = head
    for _ in range(x - 2):
        if not current.next:
            return head
        current = current.next
    if current.next:
        current.next = current.next.next
    return head

def printList(head):
    current = head
    while current:
        print(current.val, end=" -> " if current.next else "")
        current = current.next
    print()

def createList(arr):
    dummy = ListNode()
    current = dummy
    for val in arr:
        current.next = ListNode(val)
        current = current.next
    return dummy.next

if __name__ == "__main__":
    arr1 = [1, 3, 4]
    x1 = 3
    head1 = createList(arr1)
    
    print("Example 1:")
    print("Original list:")
    printList(head1)
    
    result1 = deleteNode(head1, x1)
    
    print("Modified list:")
    printList(result1)

 