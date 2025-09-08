class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_valid_bst(root, min_val=float('-inf'), max_val=float('inf')):
    if not root:
        return True

    # Current node's value must be strictly between min_val and max_val
    if not (min_val < root.val < max_val):
        return False
    
    # Recursively validate left subtree with updated max bound
    left_is_valid = is_valid_bst(root.left, min_val, root.val)
    # Recursively validate right subtree with updated min bound
    right_is_valid = is_valid_bst(root.right, root.val, max_val)

    return left_is_valid and right_is_valid
