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

def are_identical(t1, t2):
    if not t1 and not t2:
        return True
    if t1 and t2:
        return t1.val == t2.val and are_identical(t1.left, t2.left) and are_identical(t1.right, t2.right)
    return False

arr1 = list(map(lambda x: int(x) if x != "None" else None, input("Enter Tree1 nodes in level order: ").split()))
arr2 = list(map(lambda x: int(x) if x != "None" else None, input("Enter Tree2 nodes in level order: ").split()))

t1 = insert_level_order(arr1)
t2 = insert_level_order(arr2)

print("Yes" if are_identical(t1, t2) else "No")
