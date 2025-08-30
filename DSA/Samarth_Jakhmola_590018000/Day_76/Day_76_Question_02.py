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
    queue = [root]
    i = 1

    while queue and i < len(values):
        current = queue.pop(0)

        # Left child 
        if values[i] != 'N':
            current.left = Node(int(values[i]))
            queue.append(current.left)
        i += 1

        if i >= len(values):
            break
        
        # Right child
        if values[i] != 'N':
            current.right = Node(int(values[i]))
            queue.append(current.right)
        i += 1

    return root

def ancestors_of_node(root, target_node):
    if root is None:
        return False
    
    if root.data == target_node:
        return True
    
    # Check in left or right subtree
    if (ancestors_of_node(root.left, target_node) or ancestors_of_node(root.right, target_node)):
        print(root.data, end = " ")
        return True
    
    return False

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's n target_node), separated by spaces: ").split())
    target_node = int(input("Enter the target node : "))
    ancestors_of_node(build_tree(values), target_node)
except:
    print("Invalid input. Please try with a valid input.")
