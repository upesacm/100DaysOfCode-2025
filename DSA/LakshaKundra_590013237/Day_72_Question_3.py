class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def count_nodes(root):
    if not root:
        return 0
    return 1 + count_nodes(root.left) + count_nodes(root.right)

# Example 1
root1 = Node(1)
root1.left = Node(2)
root1.right = Node(3)
print(count_nodes(root1))

# Example 2
root2 = Node(5)
root2.right = Node(6)
print(count_nodes(root2))
