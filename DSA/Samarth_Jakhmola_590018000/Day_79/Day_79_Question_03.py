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

# Function to check if tree is a valid binary search tree using range-based validation
def valid_bst(root, min_val = float('-inf'), max_val = float('inf')):
    if root is None:
        return True
    if root.data <= min_val or root.data >= max_val:
        return False
    return (valid_bst(root.left, min_val, root.data) and valid_bst(root.right, root.data, max_val))


values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
print("Yes" if valid_bst(build_tree(values)) else "No")
