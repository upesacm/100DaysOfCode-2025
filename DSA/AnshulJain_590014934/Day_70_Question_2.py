class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def build_tree(nodes):
    if not nodes or nodes[0] == "N":
        return None
    root = Node(int(nodes[0]))
    queue = [root]
    i = 1
    while queue and i < len(nodes):
        current = queue.pop(0)
        if nodes[i] != "N":
            current.left = Node(int(nodes[i]))
            queue.append(current.left)
        i += 1
        if i < len(nodes) and nodes[i] != "N":
            current.right = Node(int(nodes[i]))
            queue.append(current.right)
        i += 1
    return root

def count_leaves(root):
    if not root:
        return 0
    if not root.left and not root.right:
        return 1
    return count_leaves(root.left) + count_leaves(root.right)

nodes = input().split()
root = build_tree(nodes)
print(count_leaves(root))
