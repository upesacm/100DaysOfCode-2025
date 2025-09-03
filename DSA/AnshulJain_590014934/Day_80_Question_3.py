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
def kthsmallest(root,k):
    stack=[]
    while True:
        while root:
            stack.append(root)
            root=root.left
        root=stack.pop()
        k-=1
        if k==0:
            return root.val
        root=root.right

n=list(map(int,input("Enter tree nodes: ").split()))
root=None
for x in n:
    root=insert(root,x)
k=int(input("Enter k: "))
print(kthsmallest(root,k))
