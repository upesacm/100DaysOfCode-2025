class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
def build_bst(nums):
    if not nums:
        return None
    mid = len(nums) // 2
    root = Node(nums[mid])
    root.left = build_bst(nums[:mid])
    root.right = build_bst(nums[mid+1:])
    return root
def preorder(root):
    if not root:
        return []
    return [root.val] + preorder(root.left) + preorder(root.right)
arr = list(map(int, input().split()))
tree = build_bst(arr)
print(*preorder(tree))