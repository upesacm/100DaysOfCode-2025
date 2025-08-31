class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_valid_bst(root):
    def validate(node, min_val, max_val):
        if not node:
            return True
        
        if node.val <= min_val or node.val >= max_val:
            return False
        
        return (validate(node.left, min_val, node.val) and 
                validate(node.right, node.val, max_val))
    
    return validate(root, float('-inf'), float('inf'))

# Example usage:
if __name__ == "__main__":
    # Valid BST: 2 / \ 1 3
    root1 = TreeNode(2, TreeNode(1), TreeNode(3))
    print("Yes" if is_valid_bst(root1) else "No")  # Output: Yes
    
    # Invalid BST: 5 / \ 1 4 / \ 3 6
    root2 = TreeNode(5, TreeNode(1), TreeNode(4, TreeNode(3), TreeNode(6)))
    print("Yes" if is_valid_bst(root2) else "No")  # Output: No