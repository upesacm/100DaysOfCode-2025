from collections import defaultdict, deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Function to insert nodes into BST
def insert(root, data):
    if root is None:
        return Node(data)
    if data < root.data:
        root.left = insert(root.left, data)
    elif data > root.data:
        root.right = insert(root.right, data)
    return root

# Vertical Order Traversal using BFS (Breadth First Search)
def vertical_order(root):
    if not root:
        return []
    
    column_map = {}
    q = deque([(root, 0)])   # Node + horizontal distance

    while q:
        node, hd = q.popleft()   # hd : horizontal distance
        if hd not in column_map:
            column_map[hd] = []
        column_map[hd].append(node.data)

        if node.left:
            q.append((node.left, hd - 1))
        if node.right:
            q.append((node.right, hd + 1))

    return [column_map[x] for x in sorted(column_map.keys())]

try:
    values = list(map(int, input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split()))
    root = None
    for num in values:
        root = insert(root, num)

    print(vertical_order(root))
except:
    print("Invalid input. Please try with a valid input.")
