class listnode:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next
def count_frequency(head,key):
    count=0
    current=head
    while current:
        if current.val == key:
            count += 1
        current=current.next
    return count

#example
head=listnode(1)
head.next=listnode(2)
head.next.next=listnode(1)

mid=count_frequency(head, 2)
print(mid)