class listnode:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next
def reversal(head):
    if not head or head.next:
        return head
    new_head=reversal(head)
    head.next.next=head
    head.next=None
    return new_head
