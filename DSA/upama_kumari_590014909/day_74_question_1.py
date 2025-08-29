class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def printKDistance(root, k):
    if root is None:
        return
    if k == 0:
        print(root.data, end=" ")
        return
    printKDistance(root.left, k - 1)
    printKDistance(root.right, k - 1)


root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print("Nodes at distance 2:")
printKDistance(root, 2)
