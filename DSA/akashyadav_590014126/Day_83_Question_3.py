class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def findTarget_inorder(root, k):
    def inorder(node):
        return inorder(node.left) + [node.val] + inorder(node.right) if node else []
    
    nums = inorder(root)
    left, right = 0, len(nums) - 1
    while left < right:
        total = nums[left] + nums[right]
        if total == k:
            return True
        elif total < k:
            left += 1
        else:
            right -= 1
    return False

def findTarget_hashset(root, k):
    seen = set()
    
    def dfs(node):
        if not node:
            return False
        if k - node.val in seen:
            return True
        seen.add(node.val)
        return dfs(node.left) or dfs(node.right)
    
    return dfs(root)
