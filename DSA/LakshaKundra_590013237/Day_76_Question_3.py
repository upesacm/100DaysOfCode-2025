class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

def count_nodes_at_level(root, level):
    if not root:
        return 0
    if level == 1:
        return 1
    return count_nodes_at_level(root.left, level - 1) + count_nodes_at_level(root.right, level - 1)

# Example 1
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)

print(count_nodes_at_level(root, 2))  # Output: 2

# Example 2
root = Node(10)
root.left = Node(20)
root.right = Node(30)
root.left.left = Node(40)
root.left.right = Node(50)
root.right.left = Node(60)

print(count_nodes_at_level(root, 3))  # Output: 3
