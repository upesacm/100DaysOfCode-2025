#1. line causing bug :
#return max(left_height, right_height)

#2. why ?
#The function misses adding 1 for the current node, so it only returns the height of the tallest subtree. 
#This makes the total height one less than it should be.

#correct code:
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def tree_height(root):
    if root is None:
        return 0
    left_height = tree_height(root.left)
    right_height = tree_height(root.right)
    return 1 + max(left_height, right_height)
