class node:
    def __init__(self , data):
        self.data=data
        self.prev=None
        self.next=None

def detenode(head , x):
    if head is None :
        return None
    
    if x == 1:
        new_head = head.next
        if new_head:
            new_head.prev = None
        return new_head
    
    curr = head
    for _ in range(x-1):
        if curr is None:
            return head
        curr = curr.next

    if curr is None:
        return head
    if curr.prev:
        curr.prev.next = curr.next
    if curr.next:
        curr.next.prev = curr.prev

    return head