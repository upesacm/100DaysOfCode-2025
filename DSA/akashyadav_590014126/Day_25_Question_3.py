class listnode:
    def _init__(self,val=0,next=None):
        self.val=val
        self.next=next
def reverse(head):
    prev=None
    while head:
        next_temp=head.next
        head.next=prev
        prev=head
        head=next_temp
    return prev

def addtwonumber(num1,num2):
    num1=reverse(num1)
    num2=reverse(num2)

    carry=0
    dummy=listnode(0)
    current = dummy

    while num1 or num2 or carry:
        val1=num1.val if num1 else 0
        val2=num2.val if num2 else 0
        total=val1+val2+carry

        carry=total // 10
        current.next=listnode(total%10)
        current=current.next

        if num1:num1=num1.next
        if num2:num2=num2.next
    return reverse(dummy.next)