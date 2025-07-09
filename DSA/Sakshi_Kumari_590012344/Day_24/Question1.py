Your task: Reverse the direction of a linked list by changing node connections using efficient 
pointer manipulation.
  
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def reverse_iterative(head):
    prev = None
    curr = head

    while curr:
        next_node = curr.next 
        curr.next = prev      
        prev = curr         
        curr = next_node      

    return prev 

