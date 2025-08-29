class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def isBalanced(root):
    def check(node):
        if node is None:
            return (0, True)  # height, isBalanced

        left_height, left_balanced = check(node.left)
        right_height, right_balanced = check(node.right)

        current_height = 1 + max(left_height, right_height)
        height_diff = abs(left_height - right_height)
        current_balanced = left_balanced and right_balanced and height_diff <= 1

        return (current_height, current_balanced)

    _, balanced = check(root)
    return balanced
