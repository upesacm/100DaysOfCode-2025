class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def is_balanced(root):
    def check(node):
        if not node:
            return 0
        lh = check(node.left)
        if lh == -1:
            return -1
        rh = check(node.right)
        if rh == -1:
            return -1
        if abs(lh - rh) > 1:
            return -1
        return max(lh, rh) + 1
    return check(root) != -1

root1 = Node(4)
root1.left = Node(2)
root1.right = Node(6)
root1.left.left = Node(1)
root1.left.right = Node(3)
root1.right.left = Node(5)
root1.right.right = Node(7)
print("Yes" if is_balanced(root1) else "No")

root2 = Node(1)
root2.right = Node(2)
root2.right.right = Node(3)
print("Yes" if is_balanced(root2) else "No")
