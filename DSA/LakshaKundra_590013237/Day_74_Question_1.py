class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def print_k_distance(root, k):
    if not root:
        return
    if k == 0:
        print(root.key, end=" ")
        return
    print_k_distance(root.left, k-1)
    print_k_distance(root.right, k-1)

# Example 1
root1 = Node(1)
root1.left = Node(2)
root1.right = Node(3)
root1.left.left = Node(4)
root1.left.right = Node(5)
print_k_distance(root1, 2)
print()

# Example 2
root2 = Node(10)
root2.left = Node(20)
root2.right = Node(30)
root2.left.left = Node(40)
print_k_distance(root2, 1)
print()
