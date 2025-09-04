class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def check_bst(root):
    def helper(node, min_val, max_val):
        if node is None:
            return True
        if node.value <= min_val or node.value >= max_val:
            return False
        return helper(node.left, min_val, node.value) and helper(node.right, node.value, max_val)
    
    return helper(root, float('-inf'), float('inf'))
