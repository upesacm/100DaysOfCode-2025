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

def count_nodes(root):
    if not root:
        return 0
    return 1 + count_nodes(root.left) + count_nodes(root.right)

arr = list(map(lambda x: int(x) if x != "None" else None, input("Enter tree nodes in level order: ").split()))
root = insert_level_order(arr)
print(count_nodes(root))
