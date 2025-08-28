# filepath: [day73_Question_3.py](http://_vscodecontentref_/0)
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def find_max(root):
    if not root:
        return float('-inf')
    left_max = find_max(root.left)
    right_max = find_max(root.right)
    return max(root.val, left_max, right_max)

# Example usage:
if __name__ == "__main__":
    # Tree: 3 / \ 2 5
    root1 = TreeNode(3, TreeNode(2), TreeNode(5))
    print(find_max(root1))  # Output: 5

    # Tree: 1 \ 9
    root2 = TreeNode(1, None, TreeNode(9))
    print(find_max(root2))