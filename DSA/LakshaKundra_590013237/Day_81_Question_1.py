class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def range_sum(root, L, R):
    if not root:
        return 0
    if root.val < L:
        return range_sum(root.right, L, R)
    if root.val > R:
        return range_sum(root.left, L, R)
    return root.val + range_sum(root.left, L, R) + range_sum(root.right, L, R)

root = Node(10)
root.left = Node(5)
root.right = Node(15)
root.left.left = Node(3)
root.left.right = Node(7)
root.right.right = Node(18)
print(range_sum(root, 7, 15))

root2 = Node(10)
root2.left = Node(5)
root2.right = Node(15)
root2.left.left = Node(3)
root2.left.right = Node(7)
root2.right.left = Node(13)
root2.right.right = Node(18)
print(range_sum(root2, 6, 10))
