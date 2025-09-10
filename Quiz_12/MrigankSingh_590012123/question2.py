class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def range_sum_bst(root, L, R):
    """
    Optimized range sum function using BST properties.
    The original inefficiency was traversing all nodes instead of pruning
    unnecessary subtrees based on BST ordering.
    """
    if not root:
        return 0
    
    total = 0
    
    # Add current node if in range
    if L <= root.val <= R:
        total += root.val
    
    # Only traverse left subtree if current value > L
    # (BST property: left subtree contains smaller values)
    if root.val > L:
        total += range_sum_bst(root.left, L, R)
    
    # Only traverse right subtree if current value < R  
    # (BST property: right subtree contains larger values)
    if root.val < R:
        total += range_sum_bst(root.right, L, R)
    
    return total

# Test case
root = TreeNode(10)
root.left = TreeNode(5)
root.right = TreeNode(15)
root.left.left = TreeNode(3)
root.left.right = TreeNode(7)
root.right.left = TreeNode(13)
root.right.right = TreeNode(18)
root.left.left.left = TreeNode(1)
root.left.right.left = TreeNode(6)
root.right.right.right = TreeNode(20)

result = range_sum_bst(root, 7, 15)
print(f"Range sum [7,15]: {result}")  # Correctly returns 45 (7 + 10 + 13 + 15)
