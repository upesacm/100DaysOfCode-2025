class TreeNode:
	def __init__(self, val=0, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right

def diameter_of_binary_tree(root):
	"""
	Returns the diameter (longest path between any two nodes) of a binary tree.
	The path may or may not pass through the root.
	"""
	diameter = 0
	def depth(node):
		nonlocal diameter
		if not node:
			return 0
		left = depth(node.left)
		right = depth(node.right)
		diameter = max(diameter, left + right)
		return 1 + max(left, right)
	depth(root)
	return diameter

# Example usage and test cases:
if __name__ == "__main__":
	# Tree: 1 / \ 2 3 / \ 4 5
	root1 = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))
	print("Diameter of tree 1:", diameter_of_binary_tree(root1))  # Output: 3

	# Tree: 1
	root2 = TreeNode(1)
	print("Diameter of single node tree:", diameter_of_binary_tree(root2))  # Output: 0

	# Tree: 1 / 2 / 3
	root3 = TreeNode(1, TreeNode(2, TreeNode(3)))
	print("Diameter of left-skewed tree:", diameter_of_binary_tree(root3))  # Output: 2
