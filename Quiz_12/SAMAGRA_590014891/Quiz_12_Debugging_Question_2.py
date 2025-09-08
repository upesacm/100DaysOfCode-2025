class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def range_sum_bst(root, L, R):
    if not root:
        return 0
    
    total = 0

    # include current node if it’s in range
    if L <= root.val <= R:
        total += root.val

    # only go left if there’s a chance values >= L exist
    if root.val > L:
        total += range_sum_bst(root.left, L, R)

    # only go right if there’s a chance values <= R exist
    if root.val < R:
        total += range_sum_bst(root.right, L, R)

    return total

# Bugs and Fixes

# In the first version of this code, both left and right subtrees
# were visited every single time, no matter what the node value was.
# That makes it basically a full traversal of the tree (O(n)),
# even though we don’t need to check everything.

# The whole point of having a BST is that it’s ordered:
# - if a node value is already smaller than L, then everything
#   in its left subtree will also be smaller → no need to go left.
# - if a node value is bigger than R, then everything
#   in its right subtree will also be bigger → no need to go right.
# The old code didn’t take advantage of this, it treated the tree
# like a plain binary tree.

# Fix was simple: prune the search. Only go left when node > L,
# and only go right when node < R. This skips useless work
# and makes it way faster on big trees.


# -------------------------------
# test case
# -------------------------------

#      10
#      /  \
#    5    15
#   / \   / \
#  3   7 13  18
#  /   /     \
# 1   6      20

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
