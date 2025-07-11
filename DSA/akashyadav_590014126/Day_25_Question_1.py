class listnode:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next
def is_palindrome(head:listnode)-> bool:
    if not head or head.next:
        return True
    
    slow,fast=head,head
    while fast and fast.next:
        slow=slow.next
        fast=fast.next.next

    prev=None
    curr=slow
    while curr:
        next_temp=curr.next
        curr.next=prev
        prev=curr
        curr=next_temp

    first,second=head,prev
    while second:
        if first.val != second.val:
            return False
        first=first.next
        second=second.next
    return True