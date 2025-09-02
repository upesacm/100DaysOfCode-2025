from dataclasses import dataclass
from typing import Optional

@dataclass
class Node:
    val: int
    left: Optional["Node"] = None
    right: Optional["Node"] = None

def max_value(root: Optional[Node]) -> int:

    if root is None:
        raise ValueError("Tree is empty")

    left_max = max_value(root.left) if root.left else float("-inf")
    right_max = max_value(root.right) if root.right else float("-inf")

    return max(root.val, left_max, right_max)

t1 = Node(3, Node(2), Node(5))
print(max_value(t1))  # -> 5

t2 = Node(1, None, Node(9))
print(max_value(t2))  # -> 9
