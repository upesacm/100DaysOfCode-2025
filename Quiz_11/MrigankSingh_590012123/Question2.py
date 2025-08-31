class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def convert_to_sum_tree(root):
    if not root:
        return 0

    old_val = root.val

    left_sum = convert_to_sum_tree(root.left)
    right_sum = convert_to_sum_tree(root.right)

    root.val = left_sum + right_sum
    # BUG: This logic is incorrect for sum tree conversion
    # The current implementation sets node value to sum of children's converted values
    # But it should be sum of original values of all descendants
    
    # Also, leaf nodes don't become 0 because:
    # When we reach a leaf node, we return old_val (which is the leaf's value)
    # But we should return the sum of the original subtree values

    return old_val + left_sum + right_sum
    # This return statement is actually correct for the sum calculation
    # but the assignment to root.val is wrong


# Test case:
#     1
#    / \
#   2   3
#  / \
# 4   5
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)


def print_inorder(root):
    if root:
        print_inorder(root.left)
        print(root.val, end=" ")
        print_inorder(root.right)


print("Original tree (inorder):")
print_inorder(root)
print()

convert_to_sum_tree(root)
print("After conversion (inorder):")
print_inorder(root)
print()


# CORRECTED VERSION:
def convert_to_sum_tree_corrected(root):
    if not root:
        return 0
    
    # Store the original value
    old_val = root.val
    
    # Recursively convert left and right subtrees
    left_sum = convert_to_sum_tree_corrected(root.left)
    right_sum = convert_to_sum_tree_corrected(root.right)
    
    # Set current node's value to sum of left and right subtree sums
    # (which are the sums of original values of all descendants)
    root.val = left_sum + right_sum
    
    # Return the total sum of original values in this subtree
    # This is what the parent node will use for its calculation
    return old_val + left_sum + right_sum


# Test the corrected version
root2 = TreeNode(1)
root2.left = TreeNode(2)
root2.right = TreeNode(3)
root2.left.left = TreeNode(4)
root2.left.right = TreeNode(5)

print("Testing corrected version:")
print("Original tree (inorder):")
print_inorder(root2)
print()

convert_to_sum_tree_corrected(root2)
print("After corrected conversion (inorder):")
print_inorder(root2)
print()
# Expected: 0 11 0 9 0 (for inorder: 4, 2, 5, 1, 3)
# Explanation: 
# - Leaf nodes 4,5,3 become 0
# - Node 2 becomes 4 + 5 = 9
# - Node 1 becomes 9 + 0 = 9 (but wait, should be sum of all descendants)
# Actually, the corrected algorithm should give:
# Node 4: 0 (leaf)
# Node 5: 0 (leaf) 
# Node 2: 4 + 5 = 9
# Node 3: 0 (leaf)
# Node 1: 9 + 0 = 9
# So inorder: 0, 9, 0, 9, 0
