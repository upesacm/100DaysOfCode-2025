def right_view(root):
    if not root:
        return []
    
    result = []
    q = deque([root])
    
    while q:
        level_size = len(q)

        for i in range(level_size):
            node = q.popleft()
            if i == level_size - 1:
                result.append(node.data)
            
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
    
    return result

root2 = Node(1)
root2.left = Node(2)
root2.right = Node(3)
root2.left.left = Node(4)

print("Right View:", right_view(root2)) 
