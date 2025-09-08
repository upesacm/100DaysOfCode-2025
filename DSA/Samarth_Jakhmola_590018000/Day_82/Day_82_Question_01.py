from collections import deque
import math

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Recursive function to build balanced BST
def sorted_array_to_bst(array, start, end):
    if start > end:
        return None
    mid = (start + end) // 2
    root = Node(array[mid])
    root.left = sorted_array_to_bst(array, start, mid - 1)
    root.right = sorted_array_to_bst(array, mid + 1, end)
    return root

# Preorder Traversal
def preorder(root):
    if root is None:
        return
    print(root.data, end = " ")
    preorder(root.left)
    preorder(root.right)

def height(root):
    if not root:
        return 0
    return 1 + max(height(root.left), height(root.right))

# Function to print the binary search tree
def print_binary_search_tree(root):
    print("\n")
    h = height(root)
    max_width = 2 ** h

    q = deque([root])
    level = 1
    while level <= h:
        space_between = max_width // (2 ** level)
        line = " " * (space_between // 2)
        new_q = deque()
        branch_line = ""

        for node in q:
            if node:
                line += str(node.data)
                new_q.append(node.left)
                new_q.append(node.right)
            else:
                line += " "
                new_q.append(None)
                new_q.append(None)
            line += " " * space_between

        print(line.rstrip())

        # Print branches
        if level != h:
            branch_line = ""
            for i, node in enumerate(q):
                gap = space_between // 2
                branch_line += " " * (gap // 2)
                if node:
                    branch_line += "/" if node.left else " "
                    branch_line += " " * (gap - 1)
                    branch_line += "\\" if node.right else " "
                else:
                    branch_line += " " * (gap + 1)
                branch_line += " " * (space_between - gap // 2)
            print(branch_line.rstrip())
        
        q = new_q
        level += 1

try:
    values = list(map(int, input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split()))
    root = sorted_array_to_bst(values, 0, len(values) - 1)
    preorder(root)
    print_binary_search_tree(root)
except:
    print("Invalid input. Please try with a valid input.")
