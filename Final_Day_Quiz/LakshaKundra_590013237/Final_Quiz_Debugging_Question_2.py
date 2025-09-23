#answer 1
#Bug in negative handling: Code doesn’t ignore negative paths, should use max(0, ...).

#answer 2
#Return value issue: Returns node.val + left_sum + right_sum, which double counts both sides; recursion should only extend one branch.

#answer 3
#Correct logic: Return node.val + max(left_sum, right_sum) to parent, while updating global max with node.val + left_sum + right_sum

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
            left_sum = max(0, helper(node.left))
            right_sum = max(0, helper(node.right))
            self.max_path_sum = max(self.max_path_sum, node.val + left_sum + right_sum)
            return node.val + max(left_sum, right_sum)
        helper(root)
        return self.max_path_sum

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
