# Balance BST from Sorted Array
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def sorted_array_to_bst(arr):
    if not arr: return None
    mid = len(arr) // 2
    root = Node(arr[mid])
    root.left = sorted_array_to_bst(arr[:mid])
    root.right = sorted_array_to_bst(arr[mid+1:])
    return root

def preorder(root):
    return [root.val] + preorder(root.left) + preorder(root.right) if root else []

arr = list(map(int, input().strip('[]').split(',')))
root = sorted_array_to_bst(arr)
print(*preorder(root))
