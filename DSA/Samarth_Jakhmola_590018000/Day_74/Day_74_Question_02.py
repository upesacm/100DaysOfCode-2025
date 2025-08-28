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

def balanced_tree(root):
    def check(node):
        if not node:
            return 0, True
        
        left_height, left_balanced = check(node.left)
        right_height, right_balanced = check(node.right)
        
        current_height = 1 + max(left_height, right_height)
        balanced = left_balanced and right_balanced and abs(left_height - right_height) <= 1

        return current_height, balanced
    
    return check(root)[1]

try:
    values = list(input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split())
    print("Yes" if balanced_tree(build_tree(values)) else "No")
except:
    print("Invalid input. Please try with a valid input.")
