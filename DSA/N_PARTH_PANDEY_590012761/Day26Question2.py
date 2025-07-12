class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def makeUnion(head1, head2):
    elements = set()
    
    current = head1
    while current:
        elements.add(current.val)
        current = current.next
    
    current = head2
    while current:
        elements.add(current.val)
        current = current.next
    
    sorted_elements = sorted(elements)
    
    dummy = ListNode()
    tail = dummy
    
    for num in sorted_elements:
        tail.next = ListNode(num)
        tail = tail.next
    
    return dummy.next

def print_list(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")
head1 = ListNode(9)
head1.next = ListNode(6)
head1.next.next = ListNode(4)
head1.next.next.next = ListNode(2)
head1.next.next.next.next = ListNode(3)
head1.next.next.next.next.next = ListNode(8)
head2 = ListNode(1)
head2.next = ListNode(2)
head2.next.next = ListNode(8)
head2.next.next.next = ListNode(6)
head2.next.next.next.next = ListNode(2)

print("Input:")
print("L1 = ", end="")
print_list(head1)
print("L2 = ", end="")
print_list(head2)

union_head = makeUnion(head1, head2)

print("Output:")
print_list(union_head)