from collections import deque

# Node class for Binary Tree
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Function to build tree from level-order input
def build_tree(values):
    if not values or values[0] == 'N':
        return None
    
    root = Node(int(values[0]))
    queue = deque([root])
    i = 1

    while queue and i < len(values):
        current = queue.popleft()

        # Left child 
        if values[i] != 'N':
            current.left = Node(int(values[i]))
            queue.append(current.left)
        i += 1

        # Right child
        if values[i] != 'N':
            current.right = Node(int(values[i]))
            queue.append(current.right)
        i += 1

    return root

# Function for level-order traversal
def level_order_traversal(root):
    if not root:
        return [] 

    queue = deque([root])
    result = []

    while queue:
        node = queue.popleft()
        result.append(node.data)

        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)

    return result

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
    elements = level_order_traversal((build_tree(values)))
    for i in elements:
        print(i, end = " ")
except:
    print("Invalid input. Please try with a valid input.")
