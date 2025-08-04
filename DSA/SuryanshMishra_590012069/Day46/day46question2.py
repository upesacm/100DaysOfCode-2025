# 2. Count Even and Odd Numbers in Queue
# A problem that demonstrates queue classification algorithms and teaches numerical categorization using systematic traversal methods for statistical analysis and data partitioning operations on integer datasets.

# Given a queue of integers, count and return the number of even and odd elements through systematic classification analysis. This operation is fundamental in statistical computation and data categorization where you need to partition numerical data based on mathematical properties for analytical insights. The technique involves understanding conditional traversal methods that classify elements while maintaining running counts for different categories. This concept is essential in data preprocessing, statistical analysis, and pattern recognition where numerical classification enables data understanding and facilitates further computational processing on categorized queue datasets.

# This introduces classification algorithms and conditional counting techniques that are crucial for statistical analysis and efficient numerical categorization in queue structures.

# Your task: Implement queue traversal with conditional counting to classify and enumerate even and odd elements while maintaining queue integrity and computational accuracy.

# Examples
# Input:

# [1, 2, 3, 4, 5]
# Output:

# Even: 2, Odd: 3
# Input:

# [6, 8, 10]
# Output:

# Even: 3, Odd: 0
from queue import Queue

def count_even_odd(q: Queue) -> tuple[int, int]:
    even_count = 0
    odd_count = 0
    temp = Queue()
    
    while not q.empty():
        item = q.get()
        if item % 2 == 0:
            even_count += 1
        else:
            odd_count += 1
        temp.put(item)
    
    while not temp.empty():
        q.put(temp.get())
    
    return even_count, odd_count