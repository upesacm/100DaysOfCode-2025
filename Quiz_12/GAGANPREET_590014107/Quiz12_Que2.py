#  Identify the inefficiency in the current approach 
#  --  Inefficiency
#       The function always traverses both left and right subtrees, regardless of     whether they could contain values within the range [L, R].
#       This leads to unnecessary recursive calls and wasted computation,       especially in large BSTs.

# Explain why the algorithm doesn't utilize BST properties
#  -- Failure to Use BST Properties
#          A Binary Search Tree (BST) has the property:
#            Left subtree contains values less than the current node.
#            Right subtree contains values greater than the current node.
# The current implementation ignores this and treats the tree like a regular binary tree

#  What optimizations can be made using BST characteristics? 
#  We can prune the search space:
# If root.val < L, then only the right subtree might contain values in range.
# If root.val > R, then only the left subtree might contain values in range.
# If L <= root.val <= R, include root.val and search both subtrees.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def range_sum_bst(root, L, R):
    if not root:
        return 0

    if root.val < L:
        return range_sum_bst(root.right, L, R)

    if root.val > R:
        return range_sum_bst(root.left, L, R)

    # root.val is within range
    return (root.val +
            range_sum_bst(root.left, L, R) +
            range_sum_bst(root.right, L, R))
            # Tree structure:
#      10
#     /  \
#    5    15
#   / \   / \
#  3   7 13 18
# /   /     \
#1   6      20

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

