class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class ListNode:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to build tree from level-order input
def build_tree(values):
    if not values or values[0] == 'N':
        return None
    
    root = TreeNode(int(values[0]))
    queue = [root]
    i = 1

    while queue and i < len(values):
        current = queue.pop(0)

        # Left child 
        if values[i] != 'N':
            current.left = TreeNode(int(values[i]))
            queue.append(current.left)
        i += 1

        if i >= len(values):
            break
        
        # Right child
        if values[i] != 'N':
            current.right = TreeNode(int(values[i]))
            queue.append(current.right)
        i += 1

    return root

# Convert BST to sorted linked list using inorder traversal of BST
def bst_to_list(root):
    def inorder(node):
        if not node:
            return None, None  # For head, tail
        
        # Process left subtree
        left_head, left_tail = inorder(node.left)
        
        # Current node
        new_node = ListNode(node.data)

        # Connect left tail -> current node
        if left_tail:
            left_tail.next = new_node

        # Process right subtree
        right_head, right_tail = inorder(node.right)

        # Connect current node -> right head
        new_node.next = right_head

        # New head = left_head if exists, else current node
        head = left_head if left_head else new_node

        # New head = right_tail if exists, else current node
        tail = right_head if right_head else new_node

        return head, tail
    
    head, _ = inorder(root)  # Storing head and tail
    return head

def print_list(head):
    while head:
        print(head.data, end = " -> " if head.next else "")
        head = head.next
    print()

try:
    values = list(map(int, input("Enter the TreeNodes of the tree in level order ('N' where there's no TreeNode), separated by spaces: ").split()))
    root = build_tree(values)
    list_head = bst_to_list(root)
    print_list(list_head)
except:
    print("Invalid input. Please try with a valid input.")
