class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def swap_nodes(head, k):
    if not head or not head.next:
        return head
    
    first = head
    second = head
    prev_first = None
    prev_second = None
    
    for _ in range(k - 1):
        prev_first = first
        first = first.next
        if not first:
            return head
    
    temp = first
    while temp.next:
        prev_second = second
        second = second.next
        temp = temp.next
    
    if prev_first:
        prev_first.next = second
    else:
        head = second
    
    if prev_second:
        prev_second.next = first
    else:
        head = first
    
    temp = first.next
    first.next = second.next
    second.next = temp
    
    return head

def print_list(head):
    current = head
    while current:
        print(current.val, end="->")
        current = current.next
    print("None")

head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)

print("Input:")
print_list(head)

head = swap_nodes(head, 1)

print("Output:")
print_list(head)