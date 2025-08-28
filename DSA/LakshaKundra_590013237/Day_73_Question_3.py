class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def find_max(root):
    if not root:
        return float('-inf')
    return max(root.key, find_max(root.left), find_max(root.right))

# Example 1
root1 = Node(3)
root1.left = Node(2)
root1.right = Node(5)
print(find_max(root1))

# Example 2
root2 = Node(1)
root2.right = Node(9)
print(find_max(root2))
