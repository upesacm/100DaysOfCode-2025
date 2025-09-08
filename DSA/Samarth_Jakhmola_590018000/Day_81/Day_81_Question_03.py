class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Function to insert nodes into BST
def insert(root, data):
    if root is None:
        return Node(data)
    if data < root.data:
        root.left = insert(root.left, data)
    elif data > root.data:
        root.right = insert(root.right, data)
    return root

# Function to print nodes in the range [L, R]
def print_nodes_in_range(root, L, R):
    if root is None:
        return 0
    
    # If current node is greater than L, check left
    if root.data > L:
        print_nodes_in_range(root.left, L, R)

    # If current node is in range, print it
    if L <= root.data <= R:
        print(root.data, end = " ")
        
    # If current node is smaller than R, check right
    if root.data < R:
        print_nodes_in_range(root.right, L, R)

try:
    values = list(map(int, input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split()))
    root = None
    for num in values:
        root = insert(root, num)
        
    L, R = map(int, input("Enter the values of L and R, separated by spaces : ").split())
    print_nodes_in_range(root, L, R)
except:
    print("Invalid input. Please try with a valid input.")
