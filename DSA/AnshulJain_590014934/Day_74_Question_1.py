class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def print_k_distance(root, k):
    if root is None:
        return
    if k == 0:
        print(root.data, end=' ')
        return
    print_k_distance(root.left, k-1)
    print_k_distance(root.right, k-1)

def build_tree():
    from collections import deque
    vals = input().split()
    if not vals or vals[0] == 'N':
        return None
    root = Node(int(vals[0]))
    queue = deque([root])
    i = 1
    while queue and i < len(vals):
        curr = queue.popleft()
        if vals[i] != 'N':
            curr.left = Node(int(vals[i]))
            queue.append(curr.left)
        i += 1
        if i < len(vals) and vals[i] != 'N':
            curr.right = Node(int(vals[i]))
            queue.append(curr.right)
        i += 1
    return root

root = build_tree()
k = int(input())
print_k_distance(root, k)
