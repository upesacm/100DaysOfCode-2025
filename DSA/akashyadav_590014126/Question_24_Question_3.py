class listnode:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next
def delete_at_position(head,x):
    if x==1:
        return head.next
    curr=head
    for _ in range(x-2):
        if curr is None or curr.next is None:
            return head
        curr=curr.next
    if curr.next:
        curr.next=curr.next.next
    return head