1. What’s wrong with the current logic?
In the current implementation, we do:

root.val = left_sum + right_sum
return old_val + left_sum + right_sum
Here, even though we correctly update the node’s value as the sum of its left and right subtree, 
the function still returns the old value of the node along with the sums. 
Because of this, the parent nodes end up including the leaf node’s original values in their own calculation.

2. Why leaf nodes don’t become 0?

Take a leaf node like 4.
The code sets its value to 0 (since both left and right are None).
But when returning, it sends back 4 (its old value) to the parent.
This means the parent’s sum is still influenced by the leaf’s original value, 
even though the leaf itself was updated to 0. That’s why the leaf nodes don’t really behave as expected in the final tree.

3. Correct Implementation

The fix is actually simple. Each node’s new value should be just the sum of its left and right subtrees. 
When returning back to the parent, we return the total sum of the current subtree including the original value, 
not just the modified one.

Here’s the corrected version:

def convert_to_sum_tree(root):
    if not root:
        return 0

    old_val = root.val

    left_sum = convert_to_sum_tree(root.left)
    right_sum = convert_to_sum_tree(root.right)

    root.val = left_sum + right_sum
    return root.val + old_val

