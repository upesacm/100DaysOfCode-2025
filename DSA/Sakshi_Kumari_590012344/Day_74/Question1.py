class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def print_nodes_at_k(root, k):
    if root is None:
        return
    if k == 0:
        print(root.data, end=" ")
        return
    print_nodes_at_k(root.left, k - 1)
    print_nodes_at_k(root.right, k - 1)
