class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

def print_ancestors(root, target):
    if not root:
        return False
    if root.data == target:
        return True
    if print_ancestors(root.left, target) or print_ancestors(root.right, target):
        print(root.data, end=" ")
        return True
    return False

# Example 1
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)

print_ancestors(root, 4)  # Output: 2 1

print()

# Example 2
root = Node(10)
root.left = Node(20)
root.right = Node(30)
root.left.left = Node(40)
root.left.right = Node(50)

print_ancestors(root, 50)  # Output: 20 10
