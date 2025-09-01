class Node:
    def __init__(self, value = 0, left = None, right = None):
        self.value = value
        self.left = left
        self.right = right

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

def find_min(root):
    # The minimum value is the leftmost node in the BST
    current = root
    while current and current.left:
        current = current.left
    return current.value if current else None

def find_max(root):
    # The minimum value is the rightmost node in the BST
    current = root
    while current and current.right:
        current = current.right
    return current.value if current else None

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
    root = build_tree(values)
    print(f"Min = {find_min(build_tree(values))}, Max = {find_max(build_tree(values))}")
except:
    print("Invalid input. Please try with a valid input.")
