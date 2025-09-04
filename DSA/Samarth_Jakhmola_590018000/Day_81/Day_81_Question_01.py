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

# Function to calculate sum of the elements in range [L, R]
def range_sum(root, L, R):
    if not root:
        return 0
    
    # Skip left subtree if node < L
    if root.data < L:
        return range_sum(root.right, L, R)

    # Skip right subtree if node > R
    if root.data > R:
        return range_sum(root.left, L, R)

    # If node is within the range [L, R]
    return (root.data + range_sum(root.left, L, R) + range_sum(root.right, L, R))

try:
    values = list(map(int, input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split()))
    root = build_tree(values)
    L, R = map(int, input("Enter the values of L and R, separated by spaces : ").split())
    print(range_sum(root, L, R))
except:
    print("Invalid input. Please try with a valid input.")
