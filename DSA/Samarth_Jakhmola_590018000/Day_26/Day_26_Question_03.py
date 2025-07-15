class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

def sort_linked_list(head):
    if head is None or head.next is None:
        return head
    
    zero_dummy = ListNode(-1)
    one_dummy = ListNode(-1)
    two_dummy = ListNode(-1)

    zero_tail = zero_dummy
    one_tail = one_dummy
    two_tail = two_dummy

    current = head

    while current:
        if current.val == 0:
            zero_tail.next = current
            zero_tail = zero_tail.next
        elif current.val == 1:
            one_tail.next = current
            one_tail = one_tail.next
        else:
            two_tail.next = current
            two_tail = two_tail.next
        current = current.next

    zero_tail.next = one_dummy.next if one_dummy.next else two_dummy.next
    one_tail.next = two_dummy.next
    two_tail.next = None

    return zero_dummy.next

def create_linked_list(array):
        dummy = ListNode()
        current = dummy
        for val in array:
            current.next = ListNode(val)
            current = current.next
        return dummy.next

def print_linked_list(head):
    result = []
    while head:
        result.append(str(head.val))
        head = head.next
    print("->".join(result))

head = create_linked_list(list(map(int, input("Enter the elements of the 1st linked list : ").split())))
result = sort_linked_list(head)
print_linked_list(result)
