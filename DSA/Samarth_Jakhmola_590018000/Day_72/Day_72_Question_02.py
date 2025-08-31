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
    
    root = Node(int(values[0]))
    queue = deque([root])    # Queue for level-order : Start with root in the queue
    i = 1      # Index into 'values' for the next child to process

    while queue and i < len(values):
        current = queue.popleft()   # Storing the next parent whose children will be attached

        # Attach left child if present 
        if values[i] != 'N':
            current.left = Node(int(values[i]))
            queue.append(current.left)   # Enqueue the new child whose children will be set later
        i += 1

        if i >= len(values):
            break
        
        # Attach right child if present
        if values[i] != 'N':
            current.right = Node(int(values[i]))
            queue.append(current.right)   
        i += 1                              

    return root

def identical_trees(root1, root2):
    # If both trees are empty, they are identical.
    if root1 is None and root2 is None:
        return True

    # If one tree is empty and the other is not, they aren't identical.
    if root1 is None or root2 is None:
        return False

    return(root1.data == root2.data and identical_trees(root1.left, root2.left) and identical_trees(root1.right, root2.right)) 
    
try:
    values1 = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces : ").split())
    values2 = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces : ").split())
    root1 = build_tree(values1)
    root2 = build_tree(values2)
    print("Yes" if identical_trees(root1, root2) else "No")
except:
    print("Invalid input. Please try with a valid input.")
