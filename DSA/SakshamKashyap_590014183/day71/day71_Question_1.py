class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def inorder_traversal(root):
    result = []
    def inorder(node):
        if not node:
            return
        inorder(node.left)
        result.append(node.val)
        inorder(node.right)
    inorder(root)
    return result

# Example usage:
if __name__ == "__main__":
    # Tree: 1 \ 3 / 2
    root1 = TreeNode(1, None, TreeNode(3, TreeNode(2)))
    print(inorder_traversal(root1))  # Output: [1, 2, 3]
    # Tree: 4 / \ 2 5
    root2 = TreeNode(4, TreeNode(2), TreeNode(5))
    print(inorder_traversal(root2))  # Output: [2, 4, 5]