class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_valid_bst(root, min_val=float('-inf'), max_val=float('inf')):
    """
    Fixed BST validation function.
    The original bug was only checking immediate children instead of enforcing
    the BST property for the entire subtree range.
    """
    if not root:
        return True
    
    # Check if current node violates BST property
    if not (min_val < root.val < max_val):
        return False
    
    # Recursively check left and right subtrees with updated constraints
    return (is_valid_bst(root.left, min_val, root.val) and 
            is_valid_bst(root.right, root.val, max_val))

# Test case 1: Should return False (6 < 10 in right subtree)
root = TreeNode(10)
root.left = TreeNode(5)
root.right = TreeNode(15)
root.right.left = TreeNode(6)  # This violates BST (6 < 10)
root.right.right = TreeNode(20)

result = is_valid_bst(root)
print(f"Is valid BST: {result}")  # Now correctly prints False

# Test case 2: Should return False (3 < 5 but in wrong position)
root2 = TreeNode(5)
root2.left = TreeNode(1)
root2.right = TreeNode(4)
root2.right.left = TreeNode(3)  # This violates BST (3 < 5)
root2.right.right = TreeNode(6)

result2 = is_valid_bst(root2)
print(f"Is valid BST: {result2}")  # Now correctly prints False
