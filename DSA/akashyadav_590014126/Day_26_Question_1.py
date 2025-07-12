class listnode:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next
def swap_kth(head,k):
    n=0
    temp=head
    while temp:
        n += 1
        temp=temp.next

    if k>n or 2*k - 1 == n:
        return head
    
    prevX=None
    currX=head
    for _ in range(k-1):
        prevX=currX
        currX=currX.next

    prevY=None
    currY=head
    for _ in range(n-k):
        prevY=currY
        currY=currY.next
    
    if prevX:
        prevX.next=currX
    if prevY:
        prevY.next=currY

    currX.next,currY.next = currY.next , currX.next

    if k==1:
        head = currY
    if k == n:
        head=currX