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
def transform(root, acc=0):
    if not root:
        return acc
    acc = transform(root.right, acc)
    root.val += acc
    acc = root.val
    return transform(root.left, acc)
def inorder(root):
    if not root:
        return []
    return inorder(root.left) + [root.val] + inorder(root.right)
arr = list(map(int, input().split()))
tree = None
for x in arr:
    tree = insert(tree, x)
transform(tree)
print(*inorder(tree))