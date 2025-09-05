class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def kth_smallest(root, k):
    stack = []
    while True:
        while root:
            stack.append(root)
            root = root.left
        root = stack.pop()
        k -= 1
        if k == 0:
            return root.val
        root = root.right

root = Node(3)
root.left = Node(1)
root.right = Node(4)
root.left.right = Node(2)
print(kth_smallest(root, 1))

root2 = Node(5)
root2.left = Node(3)
root2.right = Node(6)
root2.left.left = Node(2)
root2.left.right = Node(4)
root2.left.left.left = Node(1)
print(kth_smallest(root2, 3))
