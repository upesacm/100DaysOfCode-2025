class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert_level_order(arr, i=0):
    if i < len(arr) and arr[i] is not None:
        node = Node(arr[i])
        node.left = insert_level_order(arr, 2*i+1)
        node.right = insert_level_order(arr, 2*i+2)
        return node
    return None

def mirror(root):
    if root:
        root.left, root.right = root.right, root.left
        mirror(root.left)
        mirror(root.right)
    return root

def print_tree(root, space=0, gap=5):
    if root:
        space += gap
        print_tree(root.right, space)
        print(" " * (space-gap) + str(root.val))
        print_tree(root.left, space)

arr = list(map(lambda x: int(x) if x != "None" else None, input("Enter tree nodes in level order (use None for empty): ").split()))
root = insert_level_order(arr)
print("\nOriginal Tree:")
print_tree(root)
mirror(root)
print("\nMirrored Tree:")
print_tree(root)
