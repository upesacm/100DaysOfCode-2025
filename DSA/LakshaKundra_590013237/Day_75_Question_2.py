from collections import deque

class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

def right_view(root):
    if not root:
        return
    q = deque([root])
    while q:
        n = len(q)
        for i in range(n):
            node = q.popleft()
            if i == n - 1:
                print(node.data, end=" ")
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)

# Example 1
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)

right_view(root)  # Output: 1 3 4

print()

# Example 2
root = Node(10)
root.left = Node(20)
root.right = Node(30)
root.left.left = Node(40)
root.left.right = Node(50)
root.right.left = Node(60)
root.right.right = Node(70)

right_view(root)  # Output: 10 30 70
