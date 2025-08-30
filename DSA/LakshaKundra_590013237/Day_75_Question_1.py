from collections import deque

class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

def left_view(root):
    if not root:
        return
    q = deque([root])
    while q:
        n = len(q)
        for i in range(n):
            node = q.popleft()
            if i == 0:
                print(node.data, end=" ")
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)

# Example 1
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.right = Node(4)

left_view(root)  # Output: 1 2 4

print()

# Example 2
root = Node(10)
root.left = Node(20)
root.right = Node(30)
root.left.left = Node(40)
root.left.right = Node(50)
root.right.left = Node(60)
root.right.right = Node(70)

left_view(root)  # Output: 10 20 40
