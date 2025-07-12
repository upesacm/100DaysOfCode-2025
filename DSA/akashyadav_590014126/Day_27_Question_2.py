class listnode:
    def __init__(self,data):
        self.data=data
        self.prev=None
        self.next=None

def reverseDLL(head):
    if head is None or head.next is None:
        return head
    
    curr = head
    new_head=None

    while curr:
        curr.prev , curr.next = curr.next , curr.prev

        new_head=curr

        curr=curr.prev

    return new_head