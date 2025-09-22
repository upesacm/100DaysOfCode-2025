class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = self.right = None

def max_path_sum(root):
    max_sum = float('-inf')
    def helper(node):
        nonlocal max_sum
        if not node:
            return 0
        left = max(helper(node.left), 0)
        right = max(helper(node.right), 0)
        max_sum = max(max_sum, left + right + node.val)
        return max(left, right) + node.val
    helper(root)
    return max_sum

# Example 1
root1 = TreeNode(10)
root1.left = TreeNode(2)
root1.right = TreeNode(10)
root1.left.left = TreeNode(20)
root1.left.right = TreeNode(1)
root1.right.right = TreeNode(-25)
root1.right.right.left = TreeNode(3)
root1.right.right.right = TreeNode(4)
print(max_path_sum(root1))  

# Example 2
root2 = TreeNode(-10)
root2.left = TreeNode(9)
root2.right = TreeNode(20)
root2.right.left = TreeNode(15)
root2.right.right = TreeNode(7)
print(max_path_sum(root2))  