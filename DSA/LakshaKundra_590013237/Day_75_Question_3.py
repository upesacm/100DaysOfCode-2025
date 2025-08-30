class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

def diameter(root):
    def height(node):
        nonlocal max_diameter
        if not node:
            return 0
        lh = height(node.left)
        rh = height(node.right)
        max_diameter = max(max_diameter, lh + rh)
        return 1 + max(lh, rh)
    max_diameter = 0
    height(root)
    return max_diameter

# Example 1
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print(diameter(root))  # Output: 3 (Edges count) or 4 nodes in path

# Example 2
root = Node(10)
root.left = Node(20)
root.right = Node(30)
root.left.left = Node(40)
root.left.right = Node(50)
root.right.right = Node(60)
root.left.right.left = Node(70)
root.left.right.right = Node(80)

print(diameter(root))  # Output: 5
