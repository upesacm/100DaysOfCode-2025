#1. Identify the bug in handling negative path contributions 
#current_max = node.val + left_sum + right_sum
# This blindly adds left and right subtree sums, even if they are negative, which can reduce the total path sum.

# 2. Explain why the return value in helper function is incorrect 
# This is wrong because:
#It returns the entire forked path (left + node + right), which is not valid for parent recursion.
# When propagating upward, we can only choose one side (left or right), not both.

#3. What should be the correct logic for choosing maximum path extending to parent? 
class Solution:
    def _init_(self):
        self.max_path_sum = float("-inf")

    def max_path_sum_tree(self, root):
        def helper(node):
            if not node:
                return 0

            left = max(0, helper(node.left))   # Ignore negative paths
            right = max(0, helper(node.right))

            # Update global max with full path through current node
            self.max_path_sum = max(self.max_path_sum, node.val + left + right)

            # Return max path sum extending to parent
            return node.val + max(left, right)

        helper(root)
        return self.max_path_sum
