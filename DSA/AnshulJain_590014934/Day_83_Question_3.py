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
def inorder(node):
    return inorder(node.left)+[node.val]+inorder(node.right) if node else []
def two_sum_bst(root,target):
    arr=inorder(root)
    l,r=0,len(arr)-1
    while l<r:
        s=arr[l]+arr[r]
        if s==target:
            return True
        if s<target:
            l+=1
        else:
            r-=1
    return False
n=int(input())
arr=list(map(int,input().split()))
target=int(input())
root=None
for v in arr:
    root=insert(root,v)
print("Yes" if two_sum_bst(root,target) else "No")
