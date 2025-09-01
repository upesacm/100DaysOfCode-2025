class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    if not root:
        return Node(val)
    if val < root.val:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root

def inorder(root):
    if not root:
        return []
    return inorder(root.left) + [root.val] + inorder(root.right)

n = int(input())
values = list(map(int, input().split()))
new_val = int(input())
root = None
for v in values:
    root = insert(root, v)
root = insert(root, new_val)
print(*inorder(root))
