class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def sum_nodes(root):
    if not root:
        return 0
    return root.key + sum_nodes(root.left) + sum_nodes(root.right)

# Example 1
root1 = Node(1)
root1.left = Node(2)
root1.right = Node(3)
print(sum_nodes(root1))

# Example 2
root2 = Node(10)
root2.left = Node(5)
print(sum_nodes(root2))
