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

# Recursive function to calculate maximum
def maximum_in_binary_tree(root):
    if root is None:
        return float('-inf')

    left_max = maximum_in_binary_tree(root.left)
    right_max = maximum_in_binary_tree(root.right)

    return max(root.data, left_max, right_max)

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
    print(maximum_in_binary_tree(build_tree(values)))
except:
    print("Invalid input. Please try with a valid input.")
