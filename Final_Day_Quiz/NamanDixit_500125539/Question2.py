#1. current_max = node.val + left_sum + right_sum  (Bug)

#2.For the parent node, the maximum path sum should include only one path
#(either left or right) that maximizes the sum, not both.
#Including both subtrees forces a path that spans both children, which may
# not be optimal (e.g., negative sums drag down the total).
#It doesn’t allow excluding negative contributions, as the parent needs the
#maximum single path (either node.val, node.val + left_sum, or node.val + right_sum).


#3. Corrected code:-
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.max_path_sum = float("-inf")

    def max_path_sum_tree(self, root):
        if not root:
            return 0

        def helper(node):
            if not node:
                return 0

            # Get maximum sum from left and right subtrees
            left_sum = helper(node.left)
            right_sum = helper(node.right)

            # Fixed: Consider all valid path combinations, ignore negative sums
            current_max = max(node.val, node.val + left_sum, node.val + right_sum, node.val + left_sum + right_sum)

            # Update global maximum
            self.max_path_sum = max(self.max_path_sum, current_max)

            # Fixed: Return max single path for parent, ignore negative sums
            return node.val + max(left_sum, right_sum, 0)

        helper(root)
        return self.max_path_sum


# Test case
root = TreeNode(10)
root.left = TreeNode(2)
root.right = TreeNode(10)
root.left.left = TreeNode(20)
root.left.right = TreeNode(1)
root.right.right = TreeNode(-25)
root.right.right.left = TreeNode(3)
root.right.right.right = TreeNode(4)

solution = Solution()
result = solution.max_path_sum_tree(root)
print(f"Maximum path sum: {result}")
