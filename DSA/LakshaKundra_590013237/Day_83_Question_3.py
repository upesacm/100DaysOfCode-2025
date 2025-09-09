class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def inorder(root, arr):
    if root:
        inorder(root.left, arr)
        arr.append(root.val)
        inorder(root.right, arr)

def two_sum_bst(root, target):
    arr = []
    inorder(root, arr)
    l, r = 0, len(arr) - 1
    while l < r:
        s = arr[l] + arr[r]
        if s == target:
            return True
        elif s < target:
            l += 1
        else:
            r -= 1
    return False

root1 = Node(5)
root1.left = Node(3)
root1.right = Node(6)
root1.left.left = Node(2)
root1.left.right = Node(4)
root1.right.right = Node(7)
print("Yes" if two_sum_bst(root1, 9) else "No")
print("Yes" if two_sum_bst(root1, 28) else "No")
