class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def printRootToLeafPaths(root):
    def dfs(node, path):
        if node is None:
            return

        path.append(str(node.data)) 

        if node.left is None and node.right is None:
            print("->".join(path))  
        else:
            dfs(node.left, path)
            dfs(node.right, path)

        path.pop()  # Backtrack

    dfs(root, [])
