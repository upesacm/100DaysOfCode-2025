class Node:
    def __init__(self,val):
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

def findmin(root):
    while root.left:
        root=root.left
    return root

def delete(root,key):
    if not root:
        return root
    if key<root.val:
        root.left=delete(root.left,key)
    elif key>root.val:
        root.right=delete(root.right,key)
    else:
        if not root.left:
            return root.right
        elif not root.right:
            return root.left
        temp=findmin(root.right)
        root.val=temp.val
        root.right=delete(root.right,temp.val)
    return root

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val,end=" ")
        inorder(root.right)

n=list(map(int,input("Enter tree nodes: ").split()))
root=None
for x in n:
    root=insert(root,x)
d=int(input("Enter node to delete: "))
root=delete(root,d)
inorder(root)
