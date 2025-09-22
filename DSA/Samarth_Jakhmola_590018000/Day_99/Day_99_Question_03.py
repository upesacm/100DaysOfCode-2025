from collections import deque

# Tree TreeNode Defintion
class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

# Function to build tree from level order input
def build_tree(values):
    if not values or values[0] == 'N':
        return None
    
    root = TreeNode(int(values[0]))
    queue = deque([root])
    i = 1

    while queue and i < len(values):
        node = queue.popleft()

        # Left child 
        if i < len(values) and values[i] != 'N':
            node.left = TreeNode(int(values[i]))
            queue.append(node.left)
        i += 1

        # Right child
        if i < len(values) and values[i] != 'N':
            node.right = TreeNode(int(values[i]))
            queue.append(node.right)
        i += 1

    return root

# Solution class
class Solution:
    def max_path_sum(self, root):
        self.max_sum = float("-inf")
        self.best_path = []

        def dfs(node):
            if not node:
                return (0, [])
            
            # Left recursion 
            left_sum, left_path = dfs(node.left)
            right_sum, right_path = dfs(node.right)

            # Ignore negatives
            if left_sum < 0:
                left_sum, left_path = 0, []
            if right_sum < 0:
                right_sum, right_path = 0, []
                
            # Current best path through this node
            current_sum = node.value + left_sum + right_sum
            current_path = left_path[::-1] + [node.value] + right_path
            
            # Update global max + path
            if current_sum > self.max_sum:
                self.max_sum = current_sum
                self.best_path = current_path

            # Return best single branch (for parent use)
            if left_sum > right_sum:
                return (node.value + left_sum, left_path + [node.value])
            else:
                return (node.value + right_sum, right_path + [node.value])
        
        dfs(root)
        return self.max_sum, self.best_path
    
values = input("Enter the nodes of the tree in level order (use 'N' for missing) : ").split()
root = build_tree(values)
solution = Solution()
max_sum, path = solution.max_path_sum(root)
print(f"{max_sum} (path : {" -> ".join(map(str, path))})")
