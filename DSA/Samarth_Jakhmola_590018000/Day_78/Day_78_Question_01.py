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

def search_in_bst(root, key):
    # If root is None, key not found.
    if not root:
        return False
    
    # If key matches the current node value
    if root.value == key:
        return True
    
    # If key is smaller, search in left subtree
    if key < root.value:
        return search_in_bst(root.left, key)
    
    # If key is greater, search in right subtree
    return search_in_bst(root.right, key)

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
    key = int(input("Enter the value you want to search for : "))
    print("Yes" if search_in_bst(build_tree(values), key) else "No")
except:
    print("Invalid input. Please try with a valid input.")
