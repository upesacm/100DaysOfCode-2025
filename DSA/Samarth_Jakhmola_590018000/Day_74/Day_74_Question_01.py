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

def print_nodes_at_distance_k(root, k):
    if root is None:
        return

    if k == 0:
        print(root.data, end = " ")
        return 
    print_nodes_at_distance_k(root.left, k - 1)
    print_nodes_at_distance_k(root.right, k - 1)


try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
    k = int(input("Enter the value of k : "))
    print_nodes_at_distance_k(build_tree(values), k)
except:
    print("Invalid input. Please try with a valid input.")
