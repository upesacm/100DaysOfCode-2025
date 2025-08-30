class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

def convert_to_sum_tree(root):
    def post_order(node):
        if node is None:
            return 0

        left_sum = post_order(node.left)
        right_sum = post_order(node.right)

        old_val = node.data

        node.data = left_sum + right_sum

        return node.data + old_val

    post_order(root)
