class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def tree_height(root):
    if root is None:
        return 0  

    left_height = tree_height(root.left)
    right_height = tree_height(root.right)

    return 1 + max(left_height, right_height)  

root = TreeNode(1)
root.left = TreeNode(2)
root.left.left = TreeNode(3)

result = tree_height(root)
print(f"Height of tree: {result}") 

single_node = TreeNode(1)
single_result = tree_height(single_node)
print(f"Height of single node: {single_result}")  
