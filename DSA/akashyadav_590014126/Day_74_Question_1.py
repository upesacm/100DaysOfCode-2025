class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def printKDistance(root, K):
    if root is None:
        return
    if K == 0:
        print(root.data, end=' ')
        return
    printKDistance(root.left, K - 1)
    printKDistance(root.right, K - 1)
