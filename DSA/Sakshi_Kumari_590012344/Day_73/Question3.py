class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def find_max(root):
    if root is None:
        return float('-inf')
    
    left_max = find_max(root.left)
    right_max = find_max(root.right)
    
    return max(root.value, left_max, right_max)

    
