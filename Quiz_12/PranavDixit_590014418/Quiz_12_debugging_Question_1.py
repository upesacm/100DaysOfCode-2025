class TreeNode: 
    def __init__(self, val=0, left=None, right=None): 
        self.val = val 
        self.left = left 
        self.right = right 

def is_valid_bst(root): 
    if not root: 
        return True 
    
    if root.left and root.left.val >= root.val: 
        return False 
    
    if root.right and root.right.val <= root.val: 
        return False 
    
    return is_valid_bst(root.left) and is_valid_bst(root.right) 

root = TreeNode(10) 
root.left = TreeNode(5) 
root.right = TreeNode(15) 
root.right.left = TreeNode(6) 
root.right.right = TreeNode(20) 
result = is_valid_bst(root) 
print(f"Is valid BST: {result}")  

root2 = TreeNode(5) 
root2.left = TreeNode(1) 
root2.right = TreeNode(4) 
root2.right.left = TreeNode(3) 
root2.right.right = TreeNode(6) 
result2 = is_valid_bst(root2) 
print(f"Is valid BST: {result2}")  

# Flaw: The function only validates direct children instead of enforcing global min/max constraints across the entire subtree.
# Cause: This allows deeper descendants (like 6 under 15 in the right subtree of 10) to violate BST rules undetected, leading to incorrect True results.
