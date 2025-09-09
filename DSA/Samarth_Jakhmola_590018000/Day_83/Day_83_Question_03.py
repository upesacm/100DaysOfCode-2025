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

# Inorder traversal -> Sorted array
def inorder(root, array):
    if not root:
        return 
    inorder(root.left, array)
    array.append(root.data)
    inorder(root.right, array)

# Check if there exist two nodes with sum = target
def two_sums(root, target):
    nums = []
    inorder(root, nums)

    left, right = 0, len(nums) - 1
    while left < right:
        s = nums[left] + nums[right]
        if s == target:
            return True
        elif s < target:
            left += 1
        else:
            right -= 1
    return False

try:
    values = list(map(int, input("Enter the nodes of the tree in level order ('N' where there's no node), separated by spaces: ").split()))
    target = int(input("Enter the target sum : "))
    root = None
    for num in values:
        root = insert(root, num)

    print("Yes" if two_sums(root, target) else "No")
except:
    print("Invalid input. Please try with a valid input.")
