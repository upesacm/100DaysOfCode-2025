class listnode:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next
def remove_delete(head:listnode)-> listnode:
    if not head or not head.next:
        return None
    
    slow=head
    fast=head
    prev=None

    while fast and fast.next:
        fast=fast.next.next
        prev=slow
        slow=fast.next

    prev.next=slow.next
    return head