1. the function only compares each node with its immediate children. It does not enforce the global constraint that all values in the left subtree 
must be < the node and all values in the right subtree must be > the node (i.e., it lacks ancestor-based min/max bounds).


2.
    10
   /  \
  5    15
      /  \
     6   20
The code checks 15 vs 10 (OK) and 6 vs 15 (OK).

Because 6 is only compared to its parent 15, the code thinks 6 is valid even though 6 < 10 and lies in the right subtree of 10 — that violates the BST rule.
So the function returns True incorrectly. Your second test happens to fail the immediate-child check (4 ≤ 5) so it returns False, but that doesn’t mean the 
algorithm is correct in general.


Corrected code:
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_valid_bst(root):
    def helper(node, low, high):
        if not node:
            return True
        # Node value must be within the allowed range
        if not (low < node.val < high):
            return False
        # Left subtree must be < node.val, right subtree must be > node.val
        return helper(node.left, low, node.val) and helper(node.right, node.val, high)
    
    return helper(root, float("-inf"), float("inf"))


# Test case 1
root = TreeNode(10)
root.left = TreeNode(5)
root.right = TreeNode(15)
root.right.left = TreeNode(6)
root.right.right = TreeNode(20)

print("Is valid BST:", is_valid_bst(root)) 


# Test case 2
root2 = TreeNode(5)
root2.left = TreeNode(1)
root2.right = TreeNode(4)
root2.right.left = TreeNode(3)
root2.right.right = TreeNode(6)

print("Is valid BST:", is_valid_bst(root2))  
