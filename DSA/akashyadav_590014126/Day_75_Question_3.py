class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

def diameter_of_binary_tree(root):
    diameter = [0]  

    def height(node):
        if not node:
            return 0
        left_height = height(node.left)
        right_height = height(node.right)

        diameter[0] = max(diameter[0], left_height + right_height)

        return 1 + max(left_height, right_height)

    height(root)
    return diameter[0]