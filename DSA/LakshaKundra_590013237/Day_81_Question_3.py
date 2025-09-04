class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def print_range(root, L, R):
    if not root:
        return
    if root.val > L:
        print_range(root.left, L, R)
    if L <= root.val <= R:
        print(root.val, end=" ")
    if root.val < R:
        print_range(root.right, L, R)

root = Node(10)
root.left = Node(5)
root.right = Node(15)
root.left.left = Node(3)
root.left.right = Node(7)
root.right.right = Node(18)
print_range(root, 7, 15)
print()

root2 = Node(6)
root2.left = Node(2)
root2.right = Node(8)
root2.left.left = Node(0)
root2.left.right = Node(4)
root2.right.left = Node(7)
root2.right.right = Node(9)
print_range(root2, 2, 8)
print()
