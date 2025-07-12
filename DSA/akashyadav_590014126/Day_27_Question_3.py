class listnode:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next

def removeKth(head,k):
    if k<=0 or head is None:
        return head
    
    curr = head
    prev = None
    count = 1

    while curr:
        if count % k == 0:
            prev.next = curr.next
            curr = curr.next

        else:
            prev=curr
            curr=curr.next
        count += 1
    
    return head