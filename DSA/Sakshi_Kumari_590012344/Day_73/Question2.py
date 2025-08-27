class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def level_order_traversal(root):
    if root is None:
        return
    
    queue = [root]
    
    while queue:
        current = queue.pop(0)
        print(current.value, end=" ")
        
        if current.left:
            queue.append(current.left)
        if current.right:
            queue.append(current.right)
