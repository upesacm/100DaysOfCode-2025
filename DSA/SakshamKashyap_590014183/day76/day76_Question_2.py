class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def search_bst(root, val):
    if not root:
        return None
    
    if root.val == val:
        return root
    elif val < root.val:
        return search_bst(root.left, val)
    else:
        return search_bst(root.right, val)

# Example usage:
if __name__ == "__main__":
    # BST: 4 / \ 2 7 / \ 1 3
    root = TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(7))
    
    result1 = search_bst(root, 2)
    print("Found" if result1 else "Not Found")  # Output: Found
    
    result2 = search_bst(root, 5)
    print("Found" if result2 else "Not Found")  # Output: Not Found