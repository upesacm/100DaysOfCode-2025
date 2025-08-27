from collections import deque

# Define a tree node
class Node:
    def __init__(self, data):
        self.data = data    # Stores the value of the node
        self.left = None    # Pointer / Reference to left child (None means no child)
        self.right = None   # Pointer / Reference to right child 

# Build tree from level order input
def build_tree(values):
    if not values or values[0] == 'N':
        return None
    
    count = 0
    root = Node(int(values[0]))
    queue = deque([root])    # Queue for level-order : Start with root in the queue
    i = 1      # Index into 'values' for the next child to process
    count += 1

    while queue and i < len(values):
        current = queue.popleft()   # Storing the next parent whose children will be attached

        # Attach left child if present 
        if values[i] != 'N':
            current.left = Node(int(values[i]))
            count += 1
            queue.append(current.left)   # Enqueue the new child whose children will be set later
        i += 1

        if i >= len(values):
            break
        
        # Attach right child if present
        if values[i] != 'N':
            current.right = Node(int(values[i]))
            count += 1
            queue.append(current.right)   
        i += 1                              

    return root

def count_nodes(root):
    if root is None:
        return 0
    return 1 + count_nodes(root.left) + count_nodes(root.right)

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces : ").split())
    print(count_nodes(build_tree(values)))
except:
    print("Invalid input. Please try with a valid input.")
