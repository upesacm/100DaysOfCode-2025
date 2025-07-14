class listnode:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next
def delete_m_after_n(head,m,n):
    curr=head
    while curr:
        for _ in range(n):
            if curr is None:
                return head
            curr=curr.next
        if curr or curr.next is None:
            break
        temp=curr.next
        for _ in range(n):
            if temp is None:
                break
            temp=temp.next
        curr.next=temp
        curr=temp
    return head