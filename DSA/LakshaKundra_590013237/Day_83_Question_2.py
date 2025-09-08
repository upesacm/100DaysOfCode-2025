class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def serialize(root):
    vals = []
    def preorder(node):
        if not node:
            return
        vals.append(str(node.val))
        preorder(node.left)
        preorder(node.right)
    preorder(root)
    return ",".join(vals)

def deserialize(data):
    if not data:
        return None
    vals = list(map(int, data.split(",")))
    def build(l, r):
        if not vals or vals[0] < l or vals[0] > r:
            return None
        v = vals.pop(0)
        node = Node(v)
        node.left = build(l, v)
        node.right = build(v, r)
        return node
    return build(float("-inf"), float("inf"))

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val, end=" ")
        inorder(root.right)

root1 = Node(2)
root1.left = Node(1)
root1.right = Node(3)
s1 = serialize(root1)
print(s1)
root1_d = deserialize(s1)
inorder(root1_d)
print()

root2 = Node(5)
root2.left = Node(3)
root2.right = Node(7)
s2 = serialize(root2)
print(s2)
root2_d = deserialize(s2)
inorder(root2_d)
