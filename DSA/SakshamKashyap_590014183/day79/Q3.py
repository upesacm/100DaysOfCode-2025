class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def range_sum_bst(root, low, high):
    """
    🎯 Calculate sum of nodes in BST within [low, high] range
    Time Complexity: O(n) worst case, O(log n + k) average (k = nodes in range)
    Space Complexity: O(h) where h is height of tree
    
    Strategy: Use BST properties to prune unnecessary subtrees
    """
    if not root:
        return 0
    
    # Current node value
    current_sum = 0
    
    # If current node is in range, include it
    if low <= root.val <= high:
        current_sum = root.val
    
    # Recursively check left and right subtrees with pruning
    left_sum = 0
    right_sum = 0
    
    # Only traverse left if current value > low
    if root.val > low:
        left_sum = range_sum_bst(root.left, low, high)
    
    # Only traverse right if current value < high
    if root.val < high:
        right_sum = range_sum_bst(root.right, low, high)
    
    return current_sum + left_sum + right_sum

def range_sum_bst_iterative(root, low, high):
    """
    🚀 Iterative approach using stack for space optimization
    Time Complexity: O(n) worst case
    Space Complexity: O(h) for stack
    """
    if not root:
        return 0
    
    stack = [root]
    total_sum = 0
    
    while stack:
        node = stack.pop()
        
        if low <= node.val <= high:
            total_sum += node.val
        
        # Only add children that could contain values in range
        if node.left and node.val > low:
            stack.append(node.left)
        
        if node.right and node.val < high:
            stack.append(node.right)
    
    return total_sum

def range_nodes_in_range(root, low, high):
    """
    🔍 Helper function to get all nodes in range for verification
    """
    result = []
    
    def inorder(node):
        if not node:
            return
        
        if node.val > low:
            inorder(node.left)
        
        if low <= node.val <= high:
            result.append(node.val)
        
        if node.val < high:
            inorder(node.right)
    
    inorder(root)
    return result

def build_bst_from_array(arr):
    """Build BST from array by inserting elements"""
    if not arr:
        return None
    
    def insert(root, val):
        if not root:
            return TreeNode(val)
        if val < root.val:
            root.left = insert(root.left, val)
        else:
            root.right = insert(root.right, val)
        return root
    
    root = None
    for val in arr:
        root = insert(root, val)
    return root

def inorder_display(root):
    """Display tree in inorder for verification"""
    result = []
    def inorder(node):
        if node:
            inorder(node.left)
            result.append(node.val)
            inorder(node.right)
    inorder(root)
    return result

# 🧪 Test Cases
print("=" * 60)
print("🎯 BST RANGE SUM QUERY - EFFICIENT RANGE AGGREGATION")
print("=" * 60)

# Test Case 1: Basic range sum
print("\n📌 Test Case 1: Basic Range Sum")
arr1 = [10, 5, 15, 3, 7, 18]
root1 = build_bst_from_array(arr1)
inorder1 = inorder_display(root1)
low1, high1 = 7, 15
print(f"BST (inorder): {inorder1}")
print(f"Range [{low1}, {high1}]")
nodes_in_range1 = range_nodes_in_range(root1, low1, high1)
print(f"Nodes in range: {nodes_in_range1}")
sum1 = range_sum_bst(root1, low1, high1)
print(f"Range sum: {sum1}")  # Expected: 7 + 10 + 15 = 32

# Test Case 2: Range covering entire tree
print("\n📌 Test Case 2: Range Covering Entire Tree")
arr2 = [10, 5, 15, 3, 7, 12, 18]
root2 = build_bst_from_array(arr2)
inorder2 = inorder_display(root2)
low2, high2 = 0, 20
print(f"BST (inorder): {inorder2}")
print(f"Range [{low2}, {high2}]")
sum2 = range_sum_bst(root2, low2, high2)
print(f"Range sum: {sum2}")  # Expected: sum of all nodes

# Test Case 3: Range with no matching nodes
print("\n📌 Test Case 3: Range with No Matching Nodes")
arr3 = [10, 5, 15, 3, 7, 12, 18]
root3 = build_bst_from_array(arr3)
inorder3 = inorder_display(root3)
low3, high3 = 20, 25
print(f"BST (inorder): {inorder3}")
print(f"Range [{low3}, {high3}]")
sum3 = range_sum_bst(root3, low3, high3)
print(f"Range sum: {sum3}")  # Expected: 0

# Test Case 4: Single node in range
print("\n📌 Test Case 4: Single Node in Range")
arr4 = [10, 5, 15, 3, 7, 12, 18]
root4 = build_bst_from_array(arr4)
inorder4 = inorder_display(root4)
low4, high4 = 10, 10
print(f"BST (inorder): {inorder4}")
print(f"Range [{low4}, {high4}]")
sum4 = range_sum_bst(root4, low4, high4)
print(f"Range sum: {sum4}")  # Expected: 10

# Test Case 5: Comparing recursive vs iterative
print("\n📌 Test Case 5: Recursive vs Iterative Comparison")
arr5 = [8, 3, 10, 1, 6, 14, 4, 7, 13]
root5 = build_bst_from_array(arr5)
inorder5 = inorder_display(root5)
low5, high5 = 4, 10
print(f"BST (inorder): {inorder5}")
print(f"Range [{low5}, {high5}]")
nodes_in_range5 = range_nodes_in_range(root5, low5, high5)
print(f"Nodes in range: {nodes_in_range5}")
recursive_sum = range_sum_bst(root5, low5, high5)
iterative_sum = range_sum_bst_iterative(root5, low5, high5)
print(f"Recursive sum: {recursive_sum}")
print(f"Iterative sum: {iterative_sum}")
print(f"Results match: {recursive_sum == iterative_sum}")

# 🎯 Custom Input Section
print("\n" + "=" * 60)
print("🎯 CUSTOM INPUT TESTING")
print("=" * 60)

try:
    custom_arr = list(map(int, input("Enter BST values (space-separated): ").split()))
    range_input = input("Enter range [low, high] (space-separated): ").split()
    custom_low = int(range_input[0])
    custom_high = int(range_input[1])
    
    custom_root = build_bst_from_array(custom_arr)
    custom_inorder = inorder_display(custom_root)
    
    print(f"\n🌳 BST (inorder): {custom_inorder}")
    print(f"🎯 Range [{custom_low}, {custom_high}]")
    
    custom_nodes_in_range = range_nodes_in_range(custom_root, custom_low, custom_high)
    print(f"📊 Nodes in range: {custom_nodes_in_range}")
    
    custom_sum = range_sum_bst(custom_root, custom_low, custom_high)
    print(f"💰 Range sum: {custom_sum}")
    
    if custom_nodes_in_range:
        manual_sum = sum(custom_nodes_in_range)
        print(f"✅ Verification: {' + '.join(map(str, custom_nodes_in_range))} = {manual_sum}")
    
except:
    print("Using default values for demonstration...")
    demo_arr = [15, 10, 20, 8, 12, 16, 25]
    demo_root = build_bst_from_array(demo_arr)
    demo_inorder = inorder_display(demo_root)
    demo_low, demo_high = 10, 20
    print(f"🌳 Demo BST (inorder): {demo_inorder}")
    print(f"🎯 Range [{demo_low}, {demo_high}]")
    demo_sum = range_sum_bst(demo_root, demo_low, demo_high)
    print(f"💰 Range sum: {demo_sum}")

print("\n✅ Efficient range sum queries using BST pruning optimization!")