class listnode:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next

def separate(head):
    zero_head = zero_tail = listnode(0)
    one_head = one_tail = listnode(0)
    two_head = two_tail = listnode(0)

    curr=head
    while curr:
        if curr.data == 0:
            zero_tail.next = curr
            zero_tail = zero_tail.next
        elif curr.data == 1:
            one_tail.next = curr
            one_tail = one_tail.next
        else:
            two_tail = curr
            two_tail = two_tail.next
        
        curr = curr.next

    zero_tail.next = one_head.next if one_head.next else two_head.next

    one_tail = two_tail.next

    two_tail.next = None

    return zero_head