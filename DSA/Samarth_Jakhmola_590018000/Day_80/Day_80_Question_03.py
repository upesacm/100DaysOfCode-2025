class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(root, data):
    if root is None:
        return Node(data)
    if data < root.data:
        root.left = insert(root.left, data)
    elif data > root.data:
        root.right = insert(root.right, data)
    return root

# Inorder traversal with counting
def kth_smallest(root, k):
    stack = []
    current = root
    count = 0

    while True:
        while current:
            stack.append(current)
            current = current.left
        if not stack:
            break

        current = stack.pop()
        count += 1
        if count == k:
            return current.data
        current = current.right

    return None   # If k is out of range

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
    root = None
    for v in values:
        root = insert(root, v)

    k = int(input("Enter the value of k : "))
    print(kth_smallest(root, k))
except:
    print("Invalid input. Please try with a valid input.")
