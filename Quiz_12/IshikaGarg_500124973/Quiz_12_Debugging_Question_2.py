Problem:
def range_sum_bst(root, L, R):
    if not root:
        return 0

    total = 0
    if L <= root.val <= R:
        total += root.val

    # Always traverses both subtrees ❌
    left_sum = range_sum_bst(root.left, L, R)
    right_sum = range_sum_bst(root.right, L, R)

    return total + left_sum + right_sum



1. Inefficiency
It always traverses both left and right subtrees, even if we know they cannot contain values in the range.
For example:
If root.val < L, then all nodes in the left subtree are smaller and can’t be in range. Traversing left is wasted work.
If root.val > R, then all nodes in the right subtree are larger and can’t be in range. Traversing right is wasted work.
So this degenerates to a full traversal O(n) even though a BST could give us O(h + k) (height + number of reported nodes).

2. Why algorithm doesn’t use BST property
The function just treats the tree as a normal binary tree, ignoring the BST ordering:
BST property: Left subtree < root < Right subtree.
But the code ignores this, so it wastes time exploring guaranteed invalid subtrees.

3. Optimized version (using BST properties)

def range_sum_bst(root, L, R):
    if not root:
        return 0
    
    total = 0
    
    # If value is within range, include it
    if L <= root.val <= R:
        total += root.val
    
    # Only go left if needed
    if root.val > L:
        total += range_sum_bst(root.left, L, R)
    
    # Only go right if needed
    if root.val < R:
        total += range_sum_bst(root.right, L, R)
    
    return total

Corrected code:
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def range_sum_bst(root, L, R):
    if not root:
        return 0
    
    total = 0
    
    # If current node is within range, add it
    if L <= root.val <= R:
        total += root.val
    
    # Explore left subtree only if values might be >= L
    if root.val > L:
        total += range_sum_bst(root.left, L, R)
    
    # Explore right subtree only if values might be <= R
    if root.val < R:
        total += range_sum_bst(root.right, L, R)
    
    return total

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

