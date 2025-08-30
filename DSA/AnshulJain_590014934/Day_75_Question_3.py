class Node:
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None

def build_tree(nodes):
    if not nodes or nodes[0]=="N":
        return None
    root=Node(int(nodes[0]))
    q=[root]
    i=1
    while q and i<len(nodes):
        curr=q.pop(0)
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

def diameter_of_tree(root):
    def height(node):
        nonlocal diameter
        if not node: return 0
        left=height(node.left)
        right=height(node.right)
        diameter=max(diameter,left+right)
        return 1+max(left,right)
    diameter=0
    height(root)
    return diameter

nodes=input().split()
root=build_tree(nodes)
print(diameter_of_tree(root))
