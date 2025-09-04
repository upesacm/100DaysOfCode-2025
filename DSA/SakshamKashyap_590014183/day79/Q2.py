class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def kth_smallest(root, k):
    """
    🎯 Find Kth smallest element in BST using inorder traversal
    Time Complexity: O(H + k) where H is height
    Space Complexity: O(H) for recursion stack
    
    Strategy: Inorder traversal gives sorted order, stop at kth element
    """
    def inorder(node):
        if not node:
            return None
        
        # Traverse left subtree
        left_result = inorder(node.left)
        if left_result is not None:
            return left_result
        
        # Process current node
        nonlocal count
        count += 1
        if count == k:
            return node.val
        
        # Traverse right subtree
        return inorder(node.right)
    
    count = 0
    return inorder(root)

def kth_smallest_iterative(root, k):
    """
    🚀 Iterative approach using stack for space optimization
    Time Complexity: O(H + k)
    Space Complexity: O(H)
    """
    stack = []
    current = root
    count = 0
    
    while stack or current:
        # Go to leftmost node
        while current:
            stack.append(current)
            current = current.left
        
        # Process current node
        current = stack.pop()
        count += 1
        
        if count == k:
            return current.val
        
        # Move to right subtree
        current = current.right
    
    return None

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
print("🎯 KTH SMALLEST ELEMENT IN BST - RANK-BASED RETRIEVAL")
print("=" * 60)

# Test Case 1: Basic BST
print("\n📌 Test Case 1: Basic BST")
arr1 = [3, 1, 4, 2]
root1 = build_bst_from_array(arr1)
inorder1 = inorder_display(root1)
print(f"BST (inorder): {inorder1}")
print(f"1st smallest: {kth_smallest(root1, 1)}")  # Expected: 1
print(f"2nd smallest: {kth_smallest(root1, 2)}")  # Expected: 2
print(f"3rd smallest: {kth_smallest(root1, 3)}")  # Expected: 3

# Test Case 2: Larger BST
print("\n📌 Test Case 2: Larger BST")
arr2 = [5, 3, 6, 2, 4, 1]
root2 = build_bst_from_array(arr2)
inorder2 = inorder_display(root2)
print(f"BST (inorder): {inorder2}")
print(f"3rd smallest: {kth_smallest(root2, 3)}")  # Expected: 3
print(f"5th smallest: {kth_smallest(root2, 5)}")  # Expected: 5

# Test Case 3: Single node
print("\n📌 Test Case 3: Single Node BST")
root3 = TreeNode(42)
print(f"BST (inorder): {inorder_display(root3)}")
print(f"1st smallest: {kth_smallest(root3, 1)}")  # Expected: 42

# Test Case 4: Left-skewed tree
print("\n📌 Test Case 4: Left-skewed BST")
arr4 = [5, 4, 3, 2, 1]
root4 = build_bst_from_array(arr4)
inorder4 = inorder_display(root4)
print(f"BST (inorder): {inorder4}")
print(f"2nd smallest: {kth_smallest(root4, 2)}")  # Expected: 2
print(f"4th smallest: {kth_smallest(root4, 4)}")  # Expected: 4

# Test Case 5: Comparing recursive vs iterative
print("\n📌 Test Case 5: Recursive vs Iterative Comparison")
arr5 = [8, 3, 10, 1, 6, 14, 4, 7, 13]
root5 = build_bst_from_array(arr5)
inorder5 = inorder_display(root5)
print(f"BST (inorder): {inorder5}")
k = 5
recursive_result = kth_smallest(root5, k)
iterative_result = kth_smallest_iterative(root5, k)
print(f"Recursive approach - {k}th smallest: {recursive_result}")
print(f"Iterative approach - {k}th smallest: {iterative_result}")
print(f"Results match: {recursive_result == iterative_result}")

# 🎯 Custom Input Section
print("\n" + "=" * 60)
print("🎯 CUSTOM INPUT TESTING")
print("=" * 60)

try:
    custom_arr = list(map(int, input("Enter BST values (space-separated): ").split()))
    k_value = int(input("Enter k (to find kth smallest): "))
    
    custom_root = build_bst_from_array(custom_arr)
    custom_inorder = inorder_display(custom_root)
    
    print(f"\n🌳 BST (inorder): {custom_inorder}")
    result = kth_smallest(custom_root, k_value)
    
    if result is not None:
        print(f"🎯 {k_value}th smallest element: {result}")
    else:
        print(f"❌ k={k_value} is out of range (tree has {len(custom_inorder)} nodes)")
        
except:
    print("Using default values for demonstration...")
    demo_arr = [7, 3, 15, 1, 5, 12, 20, 4, 6]
    demo_root = build_bst_from_array(demo_arr)
    demo_inorder = inorder_display(demo_root)
    print(f"🌳 Demo BST (inorder): {demo_inorder}")
    print(f"🎯 4th smallest element: {kth_smallest(demo_root, 4)}")

print("\n✅ Efficient kth smallest retrieval using BST properties!")