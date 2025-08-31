class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_balanced(root):
    def check(node):
        if not node:
            return 0, True
        lh, lb = check(node.left)
        rh, rb = check(node.right)
        balanced = lb and rb and abs(lh - rh) <= 1
        return 1 + max(lh, rh), balanced
    return check(root)[1]

# Example usage:
if __name__ == "__main__":
    # Tree: 1 / 2 / 3
    root1 = TreeNode(1, TreeNode(2, TreeNode(3)))
    print("Yes" if is_balanced(root1) else "No")  # Output: No

    # Tree: 1 / \ 2 3
    root2 = TreeNode(1, TreeNode(2), TreeNode(3))
    print("Yes" if is_balanced(root2) else "No")  # Output: Yes