class TreeNode: 
    def __init__(self, val=0, left=None, right=None): 
        self.val = val 
        self.left = left 
        self.right = right 

def range_sum_bst(root, L, R): 
    if not root: 
        return 0 
    
    total = 0 
    
    if L <= root.val <= R: 
        total += root.val 
    
    left_sum = range_sum_bst(root.left, L, R) 
    right_sum = range_sum_bst(root.right, L, R) 
    
    return total + left_sum + right_sum 

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
print(f"Range sum [7,15]: {result}")  

# Inefficiency: Both left and right subtrees are always traversed even if their values cannot lie within [L, R].
# Reason: The algorithm ignores BST properties that allow pruning unnecessary branches.
# Optimization: Traverse left subtree only if root.val > L, traverse right subtree only if root.val < R. This reduces time complexity significantly for large trees.
