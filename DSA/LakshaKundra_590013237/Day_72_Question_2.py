class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def is_identical(t1, t2):
    if not t1 and not t2:
        return True
    if t1 and t2:
        return (t1.key == t2.key and 
                is_identical(t1.left, t2.left) and 
                is_identical(t1.right, t2.right))
    return False

# Example 1
t1 = Node(1)
t1.left = Node(2)
t1.right = Node(3)

t2 = Node(1)
t2.left = Node(2)
t2.right = Node(3)

print("Yes" if is_identical(t1, t2) else "No")

# Example 2
t3 = Node(1)
t3.left = Node(2)

t4 = Node(1)
t4.right = Node(2)

print("Yes" if is_identical(t3, t4) else "No")
