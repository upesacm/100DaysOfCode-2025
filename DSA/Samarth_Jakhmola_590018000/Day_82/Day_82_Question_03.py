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

# Reverse inorder transformation (BST -> Greater Tree)
def bst_to_greater(root, acc_sum = [0]):
    if root is None:
        return
    
    # Process right subtree
    bst_to_greater(root.right, acc_sum)

    # Update current node 
    acc_sum[0] += root.data
    root.data = acc_sum[0]

    # Process left subtree
    bst_to_greater(root.left, acc_sum)

def inorder(root):
    if root is None:
        return 
    inorder(root.left)
    print(root.data, end = " ")
    inorder(root.right)

try:
    values = list(map(int, input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split()))
    root = None
    for num in values:
        root = insert(root, num)
        
    bst_to_greater(root)
    inorder(root)
except:
    print("Invalid input. Please try with a valid input.")
