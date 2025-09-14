# Serialize & Deserialize BST
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def build_tree(values):
    if not values: return None
    nodes = [None if v == "null" else Node(int(v)) for v in values]
    kids = nodes[::-1]
    root = kids.pop()
    for node in nodes:
        if node:
            if kids: node.left = kids.pop()
            if kids: node.right = kids.pop()
    return root

class Codec:
    def serialize(self, root):
        vals = []
        def preorder(node):
            if not node: return
            vals.append(str(node.val))
            preorder(node.left)
            preorder(node.right)
        preorder(root)
        return ",".join(vals)
    
    def deserialize(self, data):
        if not data: return None
        vals = list(map(int, data.split(',')))
        def build(min_val, max_val):
            if vals and min_val < vals[0] < max_val:
                val = vals.pop(0)
                node = Node(val)
                node.left = build(min_val, val)
                node.right = build(val, max_val)
                return node
            return None
        return build(float('-inf'), float('inf'))

def inorder(root):
    return inorder(root.left) + [root.val] + inorder(root.right) if root else []

values = input().split()
root = build_tree(values)
codec = Codec()
data = codec.serialize(root)
root2 = codec.deserialize(data)
print("Serialized:")
print(data)
print("Deserialized Inorder:")
print(*inorder(root2))
