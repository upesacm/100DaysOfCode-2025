#1. if root.left and root.left.val >= root.val:
#    return False
#This ensures only the direct left child is smaller, but it does not check whether\
#all descendants in the left subtree are smaller.


#2. At node 15, left child 6 < 15 → passes.
#At root 10, right child 15 > 10 → passes.
#But 6 < 10 exists in the right subtree, violating BST rules.
#The code only checks direct children, not the whole subtree, so it wrongly returns True.

class TreeNode: 
    def __init__(self, val=0, left=None, right=None): 

        self.val = val 

        self.left = left 

        self.right = right 
def is_valid_bst(root): 

    if not root: 

        return True 
    # Check left child 
    if root.left and root.left.val >= root.val: 

        return False 
    # Check right child   

    if root.right and root.right.val <= root.val: 

        return False 
    # Recursively check subtrees 
    return is_valid_bst(root.left) and is_valid_bst(root.right) 
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
print(f"Is valid BST: {result}")  # Should print False (6 < 10), but what does it print? 
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

print(f"Is valid BST: {result2}")  # Should print False, but what does it print? 
