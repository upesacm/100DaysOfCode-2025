class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def sorted_array_to_bst(arr):
    if not arr:
        return None
    mid = len(arr) // 2
    root = Node(arr[mid])
    root.left = sorted_array_to_bst(arr[:mid])
    root.right = sorted_array_to_bst(arr[mid+1:])
    return root

def preorder(root):
    if root:
        print(root.val, end=" ")
        preorder(root.left)
        preorder(root.right)

arr1 = [1, 2, 3, 4, 5, 6, 7]
root1 = sorted_array_to_bst(arr1)
preorder(root1)
print()

arr2 = [10, 20, 30, 40]
root2 = sorted_array_to_bst(arr2)
preorder(root2)
