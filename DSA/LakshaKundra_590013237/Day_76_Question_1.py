class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

def to_sum_tree(node):
    if not node:
        return 0
    left_sum = to_sum_tree(node.left)
    right_sum = to_sum_tree(node.right)
    old_val = node.data
    node.data = left_sum + right_sum
    return node.data + old_val

def preorder(node):
    if not node:
        return
    print(node.data, end=" ")
    preorder(node.left)
    preorder(node.right)

# Example 1
root = Node(10)
root.left = Node(-2)
root.right = Node(6)
root.left.left = Node(8)
root.left.right = Node(-4)
root.right.left = Node(7)
root.right.right = Node(5)

to_sum_tree(root)
preorder(root)  # Output: 20 4 0 0 12 0 0

print()

# Example 2
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

to_sum_tree(root)
preorder(root)  # Output: 14 9 0 0 0 3 0
