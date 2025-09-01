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

def search(root, key):
    while root:
        if root.val == key:
            return True
        elif key < root.val:
            root = root.left
        else:
            root = root.right
    return False

n = int(input())
values = list(map(int, input().split()))
key = int(input())
root = None
for v in values:
    root = insert(root, v)
print("Yes" if search(root, key) else "No")
