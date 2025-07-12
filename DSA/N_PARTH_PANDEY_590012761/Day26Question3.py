class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def sortList(head):
    if not head or not head.next:
        return head
    
    zero_head = ListNode()
    one_head = ListNode()
    two_head = ListNode()
    
    zero = zero_head
    one = one_head
    two = two_head
    
    current = head
    while current:
        if current.val == 0:
            zero.next = current
            zero = zero.next
        elif current.val == 1:
            one.next = current
            one = one.next
        else:
            two.next = current
            two = two.next
        current = current.next
    
    zero.next = one_head.next if one_head.next else two_head.next
    one.next = two_head.next
    two.next = None
    
    return zero_head.next

def print_list(head):
    current = head
    while current:
        print(current.val, end=" → ")
        current = current.next
    print("None")

# Create the linked list: 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(2)
head.next.next.next = ListNode(1)
head.next.next.next.next = ListNode(2)
head.next.next.next.next.next = ListNode(0)
head.next.next.next.next.next.next = ListNode(2)
head.next.next.next.next.next.next.next = ListNode(2)

print("Input:")
print_list(head)

sorted_head = sortList(head)

print("Output:")
print_list(sorted_head)