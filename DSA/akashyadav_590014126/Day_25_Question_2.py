class listnode:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next
def intersection(head1:listnode,head2:listnode)->listnode:
    dummy=listnode(0)
    tail=dummy
    p1,p2=head1,head2

    while p1 and p2:
        if p1.val == p2.val:
            tail.next = listnode(p1.val)
            tail=tail.next
            p1=p1.next
            p2=p2.next
        elif p1.val < p2.val:
            p1=p1.next
        else:
            p2=p2.next

    return dummy.next