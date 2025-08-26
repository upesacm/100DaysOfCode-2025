class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_identical(root1, root2):
    if not root1 and not root2:
        return True
    if not root1 or not root2 or root1.val != root2.val:
        return False
    return is_identical(root1.left, root2.left) and is_identical(root1.right, root2.right)

# Example usage:
if __name__ == "__main__":
    # Tree1: 1 2 3
    t1 = TreeNode(1, TreeNode(2), TreeNode(3))
    t2 = TreeNode(1, TreeNode(2), TreeNode(3))
    print("Yes" if is_identical(t1, t2) else "No")  # Output: Yes

    # Tree1: 1 2, Tree2: 1 null 2
    t3 = TreeNode(1, TreeNode(2))
    t4 = TreeNode(1, None, TreeNode(2))
    print("Yes" if is_identical(t3, t4) else "No")  # Output: No