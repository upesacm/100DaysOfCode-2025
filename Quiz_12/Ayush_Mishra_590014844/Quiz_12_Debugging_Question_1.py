class TreeNode: 
    def __init__(self, val=0, left=None, right=None): 
        self.val = val 
        self.left = left 
        self.right = right 

# Corrected version of is_valid_bst with min/max constraints
def is_valid_bst(root, min_val=float('-inf'), max_val=float('inf')): 
    if not root: 
        return True 

    # Correction: Instead of checking only immediate children,
    # we now validate the current node against allowed min/max range
    if not (min_val < root.val < max_val): 
        return False 

    # Correction: Pass updated constraints to left and right subtrees
    return (is_valid_bst(root.left, min_val, root.val) and 
            is_valid_bst(root.right, root.val, max_val)) 

# Test case that reveals the bug: 
#     10 
#    /  \ 
#   5    15 
#       /  \ 
#      6   20 
root = TreeNode(10) 
root.left = TreeNode(5) 
root.right = TreeNode(15) 
root.right.left = TreeNode(6) 
root.right.right = TreeNode(20) 

result = is_valid_bst(root) 
print(f"Is valid BST: {result}")

# Another test case: 
#     5 
#    / \ 
#  1   4 
#       / \ 
#      3   6 
root2 = TreeNode(5) 
root2.left = TreeNode(1) 
root2.right = TreeNode(4) 
root2.right.left = TreeNode(3) 
root2.right.right = TreeNode(6) 

result2 = is_valid_bst(root2) 
print(f"Is valid BST: {result2}")
