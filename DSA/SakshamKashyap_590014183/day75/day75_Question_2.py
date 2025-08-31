class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def lowest_common_ancestor(root, p, q):
    if not root or root.val == p or root.val == q:
        return root
    left = lowest_common_ancestor(root.left, p, q)
    right = lowest_common_ancestor(root.right, p, q)
    if left and right:
        return root
    return left if left else right

# Example usage:
if __name__ == "__main__":
    # Tree:    3
    #         / \
    #        5   1
    #       / \
    #      6   2
    root = TreeNode(3, TreeNode(5, TreeNode(6), TreeNode(2)), TreeNode(1))
    lca = lowest_common_ancestor(root, 6, 2)
    print(lca.val if lca else None)  # Output: 5