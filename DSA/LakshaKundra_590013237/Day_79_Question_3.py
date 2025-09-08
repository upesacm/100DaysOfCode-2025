class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def is_valid_bst(root, low=float('-inf'), high=float('inf')):
    if not root:
        return True
    if not (low < root.val < high):
        return False
    return is_valid_bst(root.left, low, root.val) and is_valid_bst(root.right, root.val, high)

root = Node(2)
root.left = Node(1)
root.right = Node(3)
print("Yes" if is_valid_bst(root) else "No")

root2 = Node(5)
root2.left = Node(1)
root2.right = Node(4)
root2.right.left = Node(3)
root2.right.right = Node(6)
print("Yes" if is_valid_bst(root2) else "No")
