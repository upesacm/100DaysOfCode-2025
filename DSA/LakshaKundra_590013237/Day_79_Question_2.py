class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def count_nodes(root):
    if not root:
        return 0
    return 1 + count_nodes(root.left) + count_nodes(root.right)

root = Node(5)
root.left = Node(3)
root.right = Node(7)
print(count_nodes(root))

root2 = Node(8)
root2.left = Node(6)
root2.right = Node(10)
root2.left.left = Node(4)
print(count_nodes(root2))
