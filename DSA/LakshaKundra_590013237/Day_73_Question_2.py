from collections import deque

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def level_order(root):
    if not root:
        return
    q = deque([root])
    while q:
        node = q.popleft()
        print(node.key, end=" ")
        if node.left:
            q.append(node.left)
        if node.right:
            q.append(node.right)

# Example 1
root1 = Node(1)
root1.left = Node(2)
root1.right = Node(3)
level_order(root1)
print()

# Example 2
root2 = Node(10)
root2.right = Node(20)
level_order(root2)
print()
