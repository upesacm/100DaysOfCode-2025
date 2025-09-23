1. Bug in handling negative path contributions

Currently:

left_sum = helper(node.left)
right_sum = helper(node.right)
It doesn’t discard negative sums.

Problem: If left_sum or right_sum is negative, including them reduces the path sum.
Fix:
left_sum = max(helper(node.left), 0)
right_sum = max(helper(node.right), 0)

2. Why return value is incorrect

Currently returns:
return node.val + left_sum + right_sum
This is wrong because a parent can only extend one branch (either left or right), not both.
If you return both, you force the parent to take an impossible “V” shaped path.

3. Correct logic for recursion return
At each node, two things happen:
Update global max with the best path through the current node:
self.max_path_sum = max(self.max_path_sum, node.val + left_sum + right_sum)
(this considers both left and right children forming a complete path).
Return to parent the best single-branch extension:
return node.val + max(left_sum, right_sum)

(parent can only choose one side).

Corrected Implementation:
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.max_path_sum = float("-inf")

    def max_path_sum_tree(self, root):
        def helper(node):
            if not node:
                return 0

            # Ignore negative paths
            left_sum = max(helper(node.left), 0)
            right_sum = max(helper(node.right), 0)

            # Path through current node
            current_max = node.val + left_sum + right_sum
            self.max_path_sum = max(self.max_path_sum, current_max)

            # Return best single branch to parent
            return node.val + max(left_sum, right_sum)

        helper(root)
        return self.max_path_sum

Correct Output for Given Test:
Maximum path sum: 42
