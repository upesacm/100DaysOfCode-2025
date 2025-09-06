class Node:
    def __init__(self, val):
        self.val=val
        self.left=None
        self.right=None

def insert(root,val):
    if not root:
        return Node(val)
    if val<root.val:
        root.left=insert(root.left,val)
    else:
        root.right=insert(root.right,val)
    return root

def serialize(root):
    vals=[]
    def preorder(node):
        if not node: return
        vals.append(str(node.val))
        preorder(node.left)
        preorder(node.right)
    preorder(root)
    return ",".join(vals)

def deserialize(data):
    if not data: return None
    vals=list(map(int,data.split(",")))
    def build(lower,upper):
        nonlocal i
        if i==len(vals): return None
        val=vals[i]
        if val<lower or val>upper: return None
        i+=1
        node=Node(val)
        node.left=build(lower,val)
        node.right=build(val,upper)
        return node
    i=0
    return build(float("-inf"),float("inf"))

def inorder(node):
    return inorder(node.left)+[node.val]+inorder(node.right) if node else []

n=int(input())
arr=list(map(int,input().split()))
root=None
for v in arr:
    root=insert(root,v)
s=serialize(root)
print(s)
tree=deserialize(s)
print(" ".join(map(str,inorder(tree))))
