class Node:
    def __init__(self, key):
        self.val = key
        self.left = None
        self.right = None

def range_sum_BST(root, L, R):
    if not root:
        return 0
    
    if root.val < L: 
        return range_sum_BST(root.right, L, R)
    elif root.val > R:  
        return range_sum_BST(root.left, L, R)
    else: 
        return root.val + range_sum_BST(root.left, L, R) + range_sum_BST(root.right, L, R)

root = Node(10)
root.left = Node(5)
root.right = Node(15)
root.left.left = Node(3)
root.left.right = Node(7)
root.right.right = Node(18)

print("Range Sum:", range_sum_BST(root, 7, 15))  
