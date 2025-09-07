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
def check(root):
    if not root:
        return 0, True
    lh, lb = check(root.left)
    rh, rb = check(root.right)
    return 1 + max(lh, rh), lb and rb and abs(lh - rh) <= 1
arr = list(map(int, input().split()))
tree = None
for x in arr:
    tree = insert(tree, x)
_, ok = check(tree)
print("Yes" if ok else "No")