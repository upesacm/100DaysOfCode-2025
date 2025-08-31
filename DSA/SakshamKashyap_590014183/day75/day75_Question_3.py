class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def print_k_distance_from_target(root, target, k):
    def subtree_at_distance_k(node, k):
        if not node or k < 0:
            return
        if k == 0:
            print(node.val, end=' ')
            return
        subtree_at_distance_k(node.left, k - 1)
        subtree_at_distance_k(node.right, k - 1)

    def dfs(node):
        if not node:
            return -1
        if node.val == target:
            subtree_at_distance_k(node, k)
            return 0
        left = dfs(node.left)
        if left != -1:
            if left + 1 == k:
                print(node.val, end=' ')
            else:
                subtree_at_distance_k(node.right, k - left - 2)
            return left + 1
        right = dfs(node.right)
        if right != -1:
            if right + 1 == k:
                print(node.val, end=' ')
            else:
                subtree_at_distance_k(node.left, k - right - 2)
            return right + 1
        return -1

    dfs(root)

# Example usage:
if __name__ == "__main__":
    # Tree:    1
    #         / \
    #        2   3
    #       / \
    #      4   5
    root = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))
    print_k_distance_from_target(root, 2, 1)  # Output: 4