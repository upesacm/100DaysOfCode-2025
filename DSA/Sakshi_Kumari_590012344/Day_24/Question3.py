Your task: Delete a node at a specific position while properly handling edge cases and 
maintaining list connections.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
def delete_at_position(head, x):
    if head is None:
        return None 
    if x == 1:
        return head.next 
    current = head
    for _ in range(x - 2):
        if current is None or current.next is None:
            return head  
        current = current.next
    if current.next:
        current.next = current.next.next

    return head
