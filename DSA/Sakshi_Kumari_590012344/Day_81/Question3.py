class TreeNode:
    def __init__(self, value):
        self.val = value
        self.left = None
        self.right = None

def print_nodes_in_range(root, L, R):
    if not root:
        return
    if root.val > L:
        print_nodes_in_range(root.left, L, R)
    if L <= root.val <= R:
        print(root.val)
    if root.val < R:
        print_nodes_in_range(root.right, L, R)
