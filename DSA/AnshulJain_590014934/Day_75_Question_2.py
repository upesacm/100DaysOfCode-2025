from collections import deque

class Node:
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None

def build_tree(nodes):
    if not nodes or nodes[0]=="N":
        return None
    root=Node(int(nodes[0]))
    q=deque([root])
    i=1
    while q and i<len(nodes):
        curr=q.popleft()
        if nodes[i]!="N":
            curr.left=Node(int(nodes[i]))
            q.append(curr.left)
        i+=1
        if i>=len(nodes): break
        if nodes[i]!="N":
            curr.right=Node(int(nodes[i]))
            q.append(curr.right)
        i+=1
    return root

def right_view(root):
    if not root:
        return
    q=deque([root])
    res=[]
    while q:
        n=len(q)
        for i in range(n):
            node=q.popleft()
            if i==n-1:
                res.append(str(node.val))
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
    print(" ".join(res))

nodes=input().split()
root=build_tree(nodes)
right_view(root)
