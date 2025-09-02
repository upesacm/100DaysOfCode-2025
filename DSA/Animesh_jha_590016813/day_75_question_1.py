from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def left_view(root):
    if not root:
        return []
    
    result = []
    q = deque([root])
    
    while q:
        level_size = len(q)

        for i in range(level_size):
            node = q.popleft()
            if i == 0:
                result.append(node.data)
            
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
    
    return result

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.right = Node(4)

print("Left View:", left_view(root)) 
