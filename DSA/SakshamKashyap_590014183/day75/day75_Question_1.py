class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def print_ancestors(root, target):
    if not root:
        return False
    if root.val == target:
        return True
    if print_ancestors(root.left, target) or print_ancestors(root.right, target):
        print(root.val, end=' ')
        return True
    return False

# Example usage:
if __name__ == "__main__":
    # Tree:    1
    #         / \
    #        2   3
    #       / \
    #      4   5
    root = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))
    print_ancestors(root, 5)  # Output: 2 1
    print()

