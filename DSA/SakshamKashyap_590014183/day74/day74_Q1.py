class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def print_k_distance(root, k):
    if not root:
        return
    if k == 0:
        print(root.val, end=' ')
        return
    print_k_distance(root.left, k - 1)
    print_k_distance(root.right, k - 1)

# Example usage:
if __name__ == "__main__":
    # Tree:   1
    #        / \
    #       2   3
    #      / \
    #     4   5
    root = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))
    print_k_distance(root, 2)  # Output: 4 5
    print()