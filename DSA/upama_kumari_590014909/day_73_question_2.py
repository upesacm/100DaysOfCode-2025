from collections import deque
from dataclasses import dataclass
from typing import Optional

@dataclass
class Node:
    val: int
    left: Optional["Node"] = None
    right: Optional["Node"] = None

def level_order(root: Optional[Node]) -> None:
    """
    Prints nodes of the binary tree in level order (breadth-first traversal).
    """
    if not root:
        return

    q = deque([root])  

    while q:
        curr = q.popleft()    
        print(curr.val, end=" ")
        if curr.left:
            q.append(curr.left)
        if curr.right:
            q.append(curr.right)


t1 = Node(1, Node(2), Node(3))
level_order(t1)  
print()

t2 = Node(10, None, Node(20))
level_order(t2)  
print()
