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
        if i < len(values) and values[i] != 'N':
            current.right = Node(int(values[i]))
            queue.append(current.right)
        i += 1

    return root

def diameter_of_binary_tree(root):
    max_nodes = [0]  # Stores maximum number of nodes in diameter
    diameter_path = [[]]  # Stores the actual nodes forming the diameter path

    def dfs(node):
        if not node:
            return 0, []  # Height (path from leaf to this node)
        
        # Get height and path of left and right subtrees
        left_height, left_path = dfs(node.left)
        right_height, right_path = dfs(node.right)

        # Combine paths through the current node
        current_path = left_path + [node.data] + right_path[::-1]
        total_nodes = left_height + right_height + 1

        if total_nodes > max_nodes[0]:
            max_nodes[0] = total_nodes
            diameter_path[0] = current_path

        # Return the taller path upwards
        if left_height >= right_height:
            return left_height + 1, left_path + [node.data]
        else:
            return right_height + 1, right_path + [node.data]
        
    dfs(root)
    return max_nodes[0], diameter_path[0]

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
    length, path = diameter_of_binary_tree(build_tree(values))
    print(f"{length}(Path : {" -> ".join(map(str, path))})")
except:
    print("Invalid input. Please try with a valid input.")
