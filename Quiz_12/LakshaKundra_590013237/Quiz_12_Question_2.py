#answer 1
#The function always traverses both left and right subtrees regardless of whether the values can possibly fall into [L, R].
#This means it does unnecessary work, leading to O(n) time even if most of the tree is outside the range.

#answer 2
#According to BST, All values in the left subtree are < root.val and values in the right subtree are > root.val.
#The current function ignores this ordering and explores both subtrees anyway.

#answer 3
#If root.val < L: ignore the left subtree.
#If root.val > R: ignore the right subtree.
#If L <= root.val <= R: include root and explore both sides.
#This reduces average complexity to O(h + k)

#corrected code
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def range_sum_bst(root, L, R):
    if not root:
        return 0

    # If root value is smaller than L, skip left subtree
    if root.val < L:
        return range_sum_bst(root.right, L, R)

    # If root value is greater than R, skip right subtree
    if root.val > R:
        return range_sum_bst(root.left, L, R)

    # Otherwise, root is in range → add root + recurse both sides
    return (root.val +
            range_sum_bst(root.left, L, R) +
            range_sum_bst(root.right, L, R))


# Test case:
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
print(f"Range sum [7,15]: {result}")  # Expected: 45
