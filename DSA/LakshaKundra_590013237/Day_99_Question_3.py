class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def max_path_sum(root):
    ans = float('-inf')
    def dfs(node):
        nonlocal ans
        if not node:
            return 0
        l = max(dfs(node.left), 0)
        r = max(dfs(node.right), 0)
        ans = max(ans, l + r + node.val)
        return node.val + max(l, r)
    dfs(root)
    return ans

root1 = Node(10)
root1.left = Node(2)
root1.right = Node(10)
root1.left.left = Node(20)
root1.left.right = Node(1)
root1.right.right = Node(-25)
root1.right.right.left = Node(3)
root1.right.right.right = Node(4)
print(max_path_sum(root1))

root2 = Node(-10)
root2.left = Node(9)
root2.right = Node(20)
root2.right.left = Node(15)
root2.right.right = Node(7)
print(max_path_sum(root2))
