class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseList(head):
    prev = None
    current = head
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    return prev

def printList(head):
    current = head
    while current:
        print(current.val, end=" -> " if current.next else "")
        current = current.next
    print("NULL")


if __name__ == "__main__":
    
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)

    print("Original list:")
    printList(head)

    reversed_head = reverseList(head)

    print("\nReversed list:")
    printList(reversed_head)