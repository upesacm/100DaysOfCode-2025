class TreeNode:
	def __init__(self, val=0, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right

def is_symmetric(root):
	"""
	Returns True if the binary tree is symmetric (mirror image of itself).
	"""
	def is_mirror(left, right):
		if not left and not right:
			return True
		if not left or not right:
			return False
		return (left.val == right.val and
				is_mirror(left.left, right.right) and
				is_mirror(left.right, right.left))
	if not root:
		return True
	return is_mirror(root.left, root.right)

# Example usage and test cases:
if __name__ == "__main__":
	# Symmetric tree: 1 / \ 2 2 / \ / \ 3 4 4 3
	root1 = TreeNode(1, TreeNode(2, TreeNode(3), TreeNode(4)),
						TreeNode(2, TreeNode(4), TreeNode(3)))
	print("Is tree 1 symmetric?", is_symmetric(root1))  # Output: True

	# Asymmetric tree: 1 / \ 2 2 \ 3
	root2 = TreeNode(1, TreeNode(2, right=TreeNode(3)), TreeNode(2))
	print("Is tree 2 symmetric?", is_symmetric(root2))  # Output: False

	# Single node tree
	root3 = TreeNode(1)
	print("Is single node tree symmetric?", is_symmetric(root3))  # Output: True
