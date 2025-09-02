class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.key:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    return root

def inorder(root):
    if root:
        yield from inorder(root.left)
        yield root.key
        yield from inorder(root.right)

n = int(input())
values = list(map(int, input().split()))
root = None
for v in values:
    root = insert(root, v)
print(*inorder(root))
