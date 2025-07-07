class listnode:
    def __init__(self,val=0,next=None):
        self.val=val
        self.next=next
def linked_list_elements(head):
    current = head
    while current:
        print(current.val,end=' ')
        current=current.next
    print()

#example
head=listnode(1)
head.next=listnode(2)
head.next.next=listnode(3)
print(linked_list_elements(head))