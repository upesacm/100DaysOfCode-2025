# 2. Check if All Elements in Queue are Unique
# A problem that introduces uniqueness validation techniques and teaches duplicate detection algorithms using efficient comparison methods for data integrity verification in queue structures.

# Given a queue of integers, determine whether all elements are unique (no duplicates) and return True or False. This operation is fundamental in data validation and integrity checking where you need to verify element uniqueness within queue datasets. The technique involves understanding duplicate detection methods that can use hash-based tracking or comparative analysis to identify repeated values efficiently. This concept is essential in database operations, set validation, and data quality assurance where uniqueness constraints ensure data consistency and prevent duplicate processing in queue-based systems.

# This introduces uniqueness validation algorithms and duplicate detection techniques that are crucial for data integrity verification and efficient uniqueness checking operations.

# Your task: Implement efficient duplicate detection using appropriate data structures to verify complete element uniqueness across the entire queue.

# Examples
# Input:

# [1, 2, 3, 4]
# Output:

# True
# Input:

# [1, 2, 2, 3]
# Output:

# False
from queue import Queue

def are_elements_unique(q: Queue) -> bool:
    seen = set()
    temp = Queue()
    unique = True

    while not q.empty():
        item = q.get()
        if item in seen:
            unique = False
        else:
            seen.add(item)
        temp.put(item)

    while not temp.empty():
        q.put(temp.get())

    return unique
