class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def insert_into_bst(root, val):
    if not root:
        return TreeNode(val)
    
    if val < root.val:
        root.left = insert_into_bst(root.left, val)
    else:
        root.right = insert_into_bst(root.right, val)
    
    return root

def inorder_traversal(root):
    if not root:
        return []
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right)

# Example usage:
if __name__ == "__main__":
    # BST: 4 / \ 2 7 / \ 1 3
    root = TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(7))
    
    # Insert 5
    root = insert_into_bst(root, 5)
    print(inorder_traversal(root))  # Output: [1, 2, 3, 4, 5, 7]
    
    # Insert 6
    root = insert_into_bst(root, 6)
    print(inorder_traversal(root))  # Output: [1, 2, 3, 4, 5, 6, 7]