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

def lca(root,p,q):
    while root:
        if p<root.val and q<root.val:
            root=root.left
        elif p>root.val and q>root.val:
            root=root.right
        else:
            return root.val

n=list(map(int,input("Enter tree nodes: ").split()))
root=None
for x in n:
    root=insert(root,x)
a,b=map(int,input("Enter two nodes: ").split())
print(lca(root,a,b))
