class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def insert_bst(root, val):
    """
    Insert a value into BST while maintaining BST properties.
    Time Complexity: O(log n) average, O(n) worst case
    Space Complexity: O(log n) average, O(n) worst case (recursion stack)
    """
    # Base case: create new node
    if not root:
        return TreeNode(val)
    
    # Value is smaller, insert in left subtree
    if val < root.val:
        root.left = insert_bst(root.left, val)
    
    # Value is larger, insert in right subtree
    elif val > root.val:
        root.right = insert_bst(root.right, val)
    
    # If val == root.val, we don't insert duplicates (BST property)
    
    return root

def inorder_traversal(root):
    """Helper function to print inorder traversal"""
    result = []
    def inorder(node):
        if node:
            inorder(node.left)
            result.append(node.val)
            inorder(node.right)
    inorder(root)
    return result

# Test Case 1: Insert into existing tree
#   5
#  / \
# 3   7
root1 = TreeNode(5, TreeNode(3), TreeNode(7))
print("Original tree (inorder):", inorder_traversal(root1))  # [3, 5, 7]

root1 = insert_bst(root1, 4)
print("After inserting 4:", inorder_traversal(root1))  # [3, 4, 5, 7]

# Test Case 2: Insert into single node tree
# 10
root2 = TreeNode(10)
print("Original tree (inorder):", inorder_traversal(root2))  # [10]

root2 = insert_bst(root2, 20)
print("After inserting 20:", inorder_traversal(root2))  # [10, 20]

# Test Case 3: Insert into empty tree
root3 = None
root3 = insert_bst(root3, 15)
print("Insert into empty tree:", inorder_traversal(root3))  # [15]

# Test Case 4: Insert multiple values
root4 = TreeNode(8)
values_to_insert = [3, 10, 1, 6, 14, 4, 7, 13]
for val in values_to_insert:
    root4 = insert_bst(root4, val)
print("After multiple insertions:", inorder_traversal(root4))  # [1, 3, 4, 6, 7, 8, 10, 13, 14]

# Test Case 5: Insert duplicate value (should not change tree)
original = inorder_traversal(root4)
root4 = insert_bst(root4, 8)  # Insert duplicate
after_duplicate = inorder_traversal(root4)
print("After inserting duplicate 8:", after_duplicate)
print("Tree unchanged:", original == after_duplicate)  # True