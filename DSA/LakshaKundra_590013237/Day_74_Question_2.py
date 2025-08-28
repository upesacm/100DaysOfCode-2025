class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def is_balanced(root):
    def check(node):
        if not node:
            return 0, True
        lh, lb = check(node.left)
        rh, rb = check(node.right)
        return max(lh, rh) + 1, lb and rb and abs(lh - rh) <= 1
    return check(root)[1]

# Example 1
root1 = Node(1)
root1.left = Node(2)
root1.left.left = Node(3)
print("Yes" if is_balanced(root1) else "No")

# Example 2
root2 = Node(1)
root2.left = Node(2)
root2.right = Node(3)
print("Yes" if is_balanced(root2) else "No")
