# Two Sum in BST
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def build_tree(values):
    if not values: return None
    nodes = [None if v == "null" else Node(int(v)) for v in values]
    kids = nodes[::-1]
    root = kids.pop()
    for node in nodes:
        if node:
            if kids: node.left = kids.pop()
            if kids: node.right = kids.pop()
    return root

def two_sum(root, target):
    nums = []
    def inorder(node):
        if not node: return
        inorder(node.left)
        nums.append(node.val)
        inorder(node.right)
    inorder(root)
    l, r = 0, len(nums) - 1
    while l < r:
        s = nums[l] + nums[r]
        if s == target:
            return True
        if s < target:
            l += 1
        else:
            r -= 1
    return False

values = input().split()
target = int(input())
root = build_tree(values)
print("Yes" if two_sum(root, target) else "No")
