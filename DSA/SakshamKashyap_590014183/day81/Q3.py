class TreeNode:
	def __init__(self, val=0, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right

def is_balanced(root):
	"""
	Returns True if the binary tree is height-balanced.
	Height-balanced: for every node, the heights of left and right subtrees differ by at most 1.
	"""
	def check(node):
		if not node:
			return 0, True
		left_height, left_balanced = check(node.left)
		right_height, right_balanced = check(node.right)
		balanced = left_balanced and right_balanced and abs(left_height - right_height) <= 1
		return 1 + max(left_height, right_height), balanced
	return check(root)[1]

# Example usage and test cases:
if __name__ == "__main__":
	# Balanced tree: 1 / \ 2 3
	root1 = TreeNode(1, TreeNode(2), TreeNode(3))
	print("Is tree 1 balanced?", is_balanced(root1))  # Output: True

	# Unbalanced tree: 1 / 2 / 3
	root2 = TreeNode(1, TreeNode(2, TreeNode(3)))
	print("Is tree 2 balanced?", is_balanced(root2))  # Output: False

	# Single node tree
	root3 = TreeNode(1)
	print("Is single node tree balanced?", is_balanced(root3))  # Output: True
