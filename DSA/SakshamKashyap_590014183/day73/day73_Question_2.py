from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def level_order_traversal(root):
    if not root:
        return []
    result = []
    queue = deque([root])
    while queue:
        node = queue.popleft()
        result.append(node.val)
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
    return result

# Example usage:
if __name__ == "__main__":
    # Tree: 1 / \ 2 3
    root1 = TreeNode(1, TreeNode(2), TreeNode(3))
    print(level_order_traversal(root1))  # Output: [1, 2, 3]

    # Tree: 10 \ 20
    root2 = TreeNode(10, None, TreeNode(20))
    print(level_order_traversal(root2))  # Output: [10, 20]