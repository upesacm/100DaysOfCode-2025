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

def LCA(root, n1, n2):
    if root is None:
        return None

    # If both smaller -> go left
    if n1 < root.data and n2 < root.data:
        return LCA(root.left, n1, n2)
    
    # If both greater -> go right
    if n1 > root.data and n2 > root.data:
        return LCA(root.right, n1, n2)
    
    # Otherwise, root is the LCA
    return root

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
    n1, n2 = map(int, input("Enter the two nodes separated by spaces : ").split())
    lca = LCA(build_tree(values), n1, n2)
    print(lca.data if lca else "One or both nodes not found in the tree.")
except:
    print("Invalid input. Please try with a valid input.")
