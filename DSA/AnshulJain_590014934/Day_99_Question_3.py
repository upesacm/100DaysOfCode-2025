class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def build_tree(values):
    nodes = [None if v == "null" else Node(int(v)) for v in values]
    kids = nodes[::-1]
    root = kids.pop()
    for node in nodes:
        if node:
            if kids: node.left = kids.pop()
            if kids: node.right = kids.pop()
    return root

def max_path_sum(root):
    best = float("-inf")
    def dfs(node):
        nonlocal best
        if not node: return 0
        left = max(dfs(node.left), 0)
        right = max(dfs(node.right), 0)
        best = max(best, node.val + left + right)
        return node.val + max(left, right)
    dfs(root)
    return best

values = input("Enter tree nodes in level order (use 'null' for empty): ").split()
root = build_tree(values)
print(max_path_sum(root))
