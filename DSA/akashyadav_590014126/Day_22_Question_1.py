class listnode:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next
def finding_mid(head):
    slow=fast=head
    while fast and fast.next:
        slow=slow.next
        fast=fast.next.next
    return slow

#example
head = listnode(1)
head.next = listnode(2)
head.next.next = listnode(3)

middle = finding_mid(head)
print(middle.val)