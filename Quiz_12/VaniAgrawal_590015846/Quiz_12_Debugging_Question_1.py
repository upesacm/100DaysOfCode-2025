class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_valid_bst(root, lower=float('-inf'), upper=float('inf')):
    if not root:
        return True
    if not (lower < root.val < upper):
        return False
    return is_valid_bst(root.left, lower, root.val) and is_valid_bst(root.right, root.val, upper)

# Task 1: Identify the specific flaw in the validation logic
# The original implementation only checks the immediate left and right child nodes for validity against the current node's value. It does not ensure that all nodes in the left subtree are less than the current node and all nodes in the right subtree are greater than the current node. This leads to incorrect validation when deeper subtree violations occur.

# Task 2: Why this causes incorrect behavior
# The original code does not propagate boundary constraints through recursive calls, allowing violations deeper in the tree structure to go undetected, resulting in an incorrect validation that the tree is a valid BST.

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
