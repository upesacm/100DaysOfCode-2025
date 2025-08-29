from collections import deque

class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None

def right_view(root):
    if root is None:
        return
    q = deque()
    q.append(root)
    while q:
        size = len(q)
        for i in range(size):
            node = q.popleft()
            if i == size - 1:
                print(node.data, end=" ")
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
