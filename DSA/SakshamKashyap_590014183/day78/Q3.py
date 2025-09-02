class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def find_min_bst(root):
    """
    Find minimum value in BST (leftmost node).
    Time Complexity: O(log n) average, O(n) worst case
    Space Complexity: O(1)
    """
    if not root:
        return None
    
    # Keep going left until we find the leftmost node
    while root.left:
        root = root.left
    
    return root.val

def find_max_bst(root):
    """
    Find maximum value in BST (rightmost node).
    Time Complexity: O(log n) average, O(n) worst case
    Space Complexity: O(1)
    """
    if not root:
        return None
    
    # Keep going right until we find the rightmost node
    while root.right:
        root = root.right
    
    return root.val

def find_min_max_bst(root):
    """
    Find both minimum and maximum values in BST.
    Returns tuple (min, max) or (None, None) for empty tree.
    """
    if not root:
        return None, None
    
    return find_min_bst(root), find_max_bst(root)

# Test Case 1: Complete BST
#       8
#     /   \
#    3     10
#   / \      \
#  1   6     14
root1 = TreeNode(8)
root1.left = TreeNode(3, TreeNode(1), TreeNode(6))
root1.right = TreeNode(10, None, TreeNode(14))

min_val, max_val = find_min_max_bst(root1)
print(f"Min = {min_val}, Max = {max_val}")  # Output: Min = 1, Max = 14

# Test Case 2: Single node
# 5
root2 = TreeNode(5)
min_val2, max_val2 = find_min_max_bst(root2)
print(f"Min = {min_val2}, Max = {max_val2}")  # Output: Min = 5, Max = 5

# Test Case 3: Empty tree
min_val3, max_val3 = find_min_max_bst(None)
print(f"Empty tree - Min = {min_val3}, Max = {max_val3}")  # Output: Min = None, Max = None

# Test Case 4: Left-skewed tree
#   10
#  /
# 5
#/
#1
root4 = TreeNode(10, TreeNode(5, TreeNode(1)))
min_val4, max_val4 = find_min_max_bst(root4)
print(f"Left-skewed - Min = {min_val4}, Max = {max_val4}")  # Output: Min = 1, Max = 10

# Test Case 5: Right-skewed tree
# 1
#  \
#   5
#    \
#    10
root5 = TreeNode(1, None, TreeNode(5, None, TreeNode(10)))
min_val5, max_val5 = find_min_max_bst(root5)
print(f"Right-skewed - Min = {min_val5}, Max = {max_val5}")  # Output: Min = 1, Max = 10

# Individual function calls
print("\nIndividual function calls:")
print(f"Minimum in root1: {find_min_bst(root1)}")  # 1
print(f"Maximum in root1: {find_max_bst(root1)}")  # 14
print(f"Minimum in empty tree: {find_min_bst(None)}")  # None
print(f"Maximum in empty tree: {find_max_bst(None)}")  # None