from collections import deque
class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right

def level_ordr_traversal(root):
    if not root:
        return []
    result=[]
    queue=deque([root])

    while queue:
        node=queue.popleft()
        result.append(node.val)
    
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
        
    return result