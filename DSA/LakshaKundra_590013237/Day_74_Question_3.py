class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def print_paths(root, path=[]):
    if not root:
        return
    path.append(root.key)
    if not root.left and not root.right:
        print("->".join(map(str, path)))
    else:
        print_paths(root.left, path)
        print_paths(root.right, path)
    path.pop()

# Example 1
root1 = Node(1)
root1.left = Node(2)
root1.right = Node(3)
root1.left.right = Node(5)
print_paths(root1)

# Example 2
root2 = Node(10)
root2.left = Node(20)
root2.right = Node(30)
root2.left.left = Node(40)
root2.left.right = Node(50)
print_paths(root2)
