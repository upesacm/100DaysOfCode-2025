class listnode:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next

def union(head1,head2):
    union_set=set()

    temp=head1
    while temp:
        union_set.add(temp.data)
        temp=temp.next

    temp=head2
    while temp:
        union_set.add(temp.data)
        temp=temp.next

    sorted_data=sorted(union_set)

    dummy = listnode(-1)
    curr=dummy
    for val in sorted_data:
        curr.next=listnode(val)
        curr=curr.next

    return dummy.next