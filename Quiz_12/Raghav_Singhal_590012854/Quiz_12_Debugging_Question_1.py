class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_valid_bst(root):
    def helper(node, low=float("-inf"), high=float("inf")):
        # Base case: empty tree is valid
        if not node:
            return True
        
        # Current node must be strictly between low and high
        if not (low < node.val < high):
            return False
        
        # Left subtree must be < node.val, right subtree must be > node.val
        return helper(node.left, low, node.val) and helper(node.right, node.val, high)
    
    return helper(root)


# ----------------- TEST CASES -----------------

# Test Case 1:
#      10
#     /  \
#    5    15
#        /  \
#       6    20
root = TreeNode(10)
root.left = TreeNode(5)
root.right = TreeNode(15)
root.right.left = TreeNode(6)
root.right.right = TreeNode(20)

print(f"Is valid BST: {is_valid_bst(root)}")  
# Expected Output: False  (6 < 10 but is in right subtree)


# Test Case 2:
#      5
#     / \
#    1   4
#       / \
#      3   6
root2 = TreeNode(5)
root2.left = TreeNode(1)
root2.right = TreeNode(4)
root2.right.left = TreeNode(3)
root2.right.right = TreeNode(6)

print(f"Is valid BST: {is_valid_bst(root2)}")  
# Expected Output: False  (4 < 5 but is in right subtree)


# Test Case 3: Valid BST
#       2
#      / \
#     1   3
root3 = TreeNode(2)
root3.left = TreeNode(1)
root3.right = TreeNode(3)

print(f"Is valid BST: {is_valid_bst(root3)}")  
# Expected Output: True
