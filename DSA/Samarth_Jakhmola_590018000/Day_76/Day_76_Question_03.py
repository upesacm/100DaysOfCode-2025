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

def count_nodes(root, level, nodes):
    if root is None:
        return 0
    
    # If we are at the desired level
    if level == 1:
        nodes.append(root.data)
        return 
    
    # Recurse for left and right subtrees with level - 1
    count_nodes(root.left, level - 1, nodes) 
    count_nodes(root.right, level - 1, nodes)

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's n target_node), separated by spaces: ").split())
    level = int(input("Enter the level at which the nodes are to be counted : "))
    result = []
    count_nodes(build_tree(values), level, result)
    print(f"{len(result)}", end = " ")
    print(f"(Nodes : {", ".join(map(str, result))})")
except:
    print("Invalid input. Please try with a valid input.")
