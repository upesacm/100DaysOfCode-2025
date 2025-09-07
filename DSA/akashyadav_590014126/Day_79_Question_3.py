class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def is_valid_bst(root):
    def validate(node, min_val, max_val):
        if node is None:
            return True
        if not (min_val < node.val < max_val):
            return False
        return (validate(node.left, min_val, node.val) and
                validate(node.right, node.val, max_val))
    
    return validate(root, float('-inf'), float('inf'))
