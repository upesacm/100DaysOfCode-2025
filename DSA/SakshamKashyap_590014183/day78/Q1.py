class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def search_bst(root, key):
    """
    Search for a key in BST using binary search approach.
    Time Complexity: O(log n) average, O(n) worst case
    Space Complexity: O(log n) average, O(n) worst case (recursion stack)
    """
    # Base case: empty tree or node not found
    if not root:
        return False
    
    # Found the key
    if root.val == key:
        return True
    
    # Key is smaller, search left subtree
    elif key < root.val:
        return search_bst(root.left, key)
    
    # Key is larger, search right subtree
    else:
        return search_bst(root.right, key)

# Test Case 1: Key exists in tree
#       5
#     /   \
#    3     7
#   / \   / \
#  2   4 6   8
root1 = TreeNode(5)
root1.left = TreeNode(3, TreeNode(2), TreeNode(4))
root1.right = TreeNode(7, TreeNode(6), TreeNode(8))

key1 = 4
result1 = search_bst(root1, key1)
print(f"Search for {key1}: {'Yes' if result1 else 'No'}")  # Output: Yes

# Test Case 2: Key doesn't exist
#   5
#  / \
# 3   7
key2 = 10
root2 = TreeNode(5, TreeNode(3), TreeNode(7))
result2 = search_bst(root2, key2)
print(f"Search for {key2}: {'Yes' if result2 else 'No'}")  # Output: No

# Edge case: Empty tree
result3 = search_bst(None, 5)
print(f"Search in empty tree: {'Yes' if result3 else 'No'}")  # Output: No

# Edge case: Single node
single_node = TreeNode(10)
result4 = search_bst(single_node, 10)
print(f"Search in single node (found): {'Yes' if result4 else 'No'}")  # Output: Yes

result5 = search_bst(single_node, 5)
print(f"Search in single node (not found): {'Yes' if result5 else 'No'}")  # Output: No