class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

def remove_duplicates(head):
    if head is None:
        return head

    current = head
    while current.next:
        if current.val == current.next.val:
            current.next = current.next.next  
        else:
            current = current.next 
    return head

def print_list(head):
    current = head
    while current:
        print(current.val, end=" ")
        current = current.next
    print()


head = ListNode(1)
head.next = ListNode(1)
head.next.next = ListNode(2)
head.next.next.next = ListNode(3)
head.next.next.next.next = ListNode(3)

print("Original list:")
print_list(head)

head = remove_duplicates(head)

print("After removing duplicates:")
print_list(head)
