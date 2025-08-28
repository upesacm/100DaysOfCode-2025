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

def print_all_paths(root):
    def depth_first_search(node, path):
        if not node:
            return
        
        path.append(str(node.data))

        # If leaf node, then print path
        if not node.left and not node.right:
            print("->".join(path))
        else:
            depth_first_search(node.left, path)
            depth_first_search(node.right, path)

        # Backtrack
        path.pop()

    depth_first_search(root, [])

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
    print_all_paths(build_tree(values))
except:
    print("Invalid input. Please try with a valid input.")
