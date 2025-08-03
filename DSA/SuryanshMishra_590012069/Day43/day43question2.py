# 2. Generate Binary Numbers from 1 to N using Queue
# A problem that introduces systematic number generation techniques and teaches breadth-first binary construction using queue-based pattern expansion for efficient sequence generation.

# Given a number n, generate binary numbers from 1 to n using a queue-based approach and return them as a list. This operation demonstrates systematic pattern generation where each binary number is constructed by extending previous numbers with '0' and '1' suffixes. The technique is fundamental in number system conversion and systematic enumeration where you need to generate sequences efficiently using breadth-first construction. Understanding this concept is crucial for combinatorial generation, tree traversal patterns, and systematic search algorithms where queue-based expansion produces ordered sequences naturally.

# This introduces systematic generation algorithms and breadth-first construction techniques that are crucial for number system processing and efficient sequence enumeration operations.

# Your task: Implement queue-based binary number generation by systematically expanding each number with '0' and '1' extensions using FIFO processing.

# Examples
# Input:

# n = 5
# Output:

# ["1", "10", "11", "100", "101"]
# Input:

# n = 3
# Output:

# ["1", "10", "11"]
from collections import deque

def generateBinaryNumbers(n):
    result = []
    queue = deque()
    queue.append("1")
    
    for _ in range(n):
        front = queue.popleft()
        result.append(front)
        
        queue.append(front + "0")
        queue.append(front + "1")
    
    return result