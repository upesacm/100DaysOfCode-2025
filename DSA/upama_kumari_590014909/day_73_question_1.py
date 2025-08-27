from dataclasses import dataclass
from typing import Optional

@dataclass
class Node:
    val: int
    left: Optional["Node"] = None
    right: Optional["Node"] = None

def sum_of_nodes(root: Optional[Node]) -> int:
    """
    Recursively computes the sum of all node values in the binary tree.
    """
    if root is None:
        return 0  

    return root.val + sum_of_nodes(root.left) + sum_of_nodes(root.right)


t1 = Node(1, Node(2), Node(3))
print(sum_of_nodes(t1)) 

t2 = Node(10, Node(5))
print(sum_of_nodes(t2)) 
