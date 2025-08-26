class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def mirror_tree(root):
    if not root:
        return None
    root.left, root.right = mirror_tree(root.right), mirror_tree(root.left)
    return root

# Example usage:
def inorder(root):
    if not root:
        return []
    return inorder(root.left) + [root.val] + inorder(root.right)

if __name__ == "__main__":
    # Tree:   1
    #        / \
    #       2   3
    root = TreeNode(1, TreeNode(2), TreeNode(3))
    mirror_tree(root)
    print(inorder(root))  # Output: [3, 1, 2]