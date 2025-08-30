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

def sum_tree(node):
    if node is None:
        return 0
    
    # Recursively convert left and right subtrees
    left_sum = sum_tree(node.left)
    right_sum = sum_tree(node.right)

    # Storing the original value of the node 
    old_value = node.data

    # Update the current node to sum of left and right subtree sums
    node.data = left_sum + right_sum
    
    # Return original value + updated sum for parent's calculation
    return node.data + old_value

def print_inorder(node):
    if node is None:
        return
    print_inorder(node.left)
    print(node.data, end = " ")
    print_inorder(node.right)

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
    root = build_tree(values)
    sum_tree(root)
    print_inorder(root)
except:
    print("Invalid input. Please try with a valid input.")
