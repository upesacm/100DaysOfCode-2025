1. root.val = left_sum + right_sum
return old_val + left_sum + right_sum

The recursive calls return the total sum of subtree values (including children and their descendants).
The code updates the node with only left_sum + right_sum, but that part is fine.
The problem is that leaf nodes end up with their original value instead of becoming 0. 

2. Why leaf nodes don’t become 0
For a leaf node, say 4:
convert_to_sum_tree(root.left) → 0
convert_to_sum_tree(root.right) → 0
So root.val = 0 + 0 = 0(so far, correct)
But when control returns to the parent, the function returns old_val + left_sum + right_sum, i.e., 4 + 0 + 0 = 4.
So even though the leaf node’s value was set to 0, the returned value carries the original leaf value upward.
This is correct for internal nodes (they need children’s sums), but the misunderstanding is thinking leaves aren’t zeroed — in fact they are, 
but maybe you checked the return value instead of root.val.
                                                                                                                                            
3.class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def convert_to_sum_tree(root):
    if root is None:
        return 0

    # Store the old value
    old_val = root.val

    # Recursively convert left and right subtrees
    left_sum = convert_to_sum_tree(root.left)
    right_sum = convert_to_sum_tree(root.right)

    # Update current node to sum of left + right subtree values
    root.val = left_sum + right_sum

    # Return sum of node’s original value + left + right
    return root.val + old_val
