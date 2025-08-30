class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def to_sum_tree(node):
    if node is None:
        return 0
    old_val = node.data
    node.data = to_sum_tree(node.left) + to_sum_tree(node.right)
    return node.data + old_val

def inorder(node):
    if node:
        inorder(node.left)
        print(node.data, end=" ")
        inorder(node.right)

def build_tree(nodes):
    if not nodes or nodes[0] == "N":
        return None
    root = Node(int(nodes[0]))
    q = [root]
    i = 1
    while q and i < len(nodes):
        curr = q.pop(0)
        if nodes[i] != "N":
            curr.left = Node(int(nodes[i]))
            q.append(curr.left)
        i += 1
        if i >= len(nodes):
            break
        if nodes[i] != "N":
            curr.right = Node(int(nodes[i]))
            q.append(curr.right)
        i += 1
    return root

nodes = input("Enter tree nodes in level order (use N for null): ").split()
root = build_tree(nodes)
to_sum_tree(root)
inorder(root)
