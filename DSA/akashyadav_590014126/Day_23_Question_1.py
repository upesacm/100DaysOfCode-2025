class listnode:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next
def kth_from_last(head:listnode,k:int)->int:
    fast=slow=head

    for _ in range(k):
        if not fast:
            return -1
        fast=fast.next
    while fast:
        fast=fast.next
        slow=slow.next

    return slow.val if slow else -1

#example
head=listnode(1)
head.next=listnode(2)
head.next.next=listnode(3)
head.next.next.next=listnode(4)
kth=kth_from_last(head,2)
print(kth)
