# 3. Count Occurrences of Each Element in a Queue
# A problem that teaches frequency analysis techniques and demonstrates element counting algorithms using hash-based tracking methods for statistical analysis and data profiling operations.

# Given a queue of integers, count the occurrences of each element and return the frequency distribution as a dictionary or mapping structure. This operation is fundamental in statistical analysis and data profiling where you need to analyze element frequencies within queue datasets. The technique requires understanding frequency counting methods that track element occurrences efficiently using hash-based storage. This concept is essential in data mining, pattern analysis, and statistical computing where frequency distributions provide insights into data patterns and enable further analytical processing on queue-based information.

# This teaches frequency analysis algorithms and statistical counting techniques that are essential for data profiling and efficient element frequency tracking operations.

# Your task: Implement hash-based frequency counting to analyze element occurrences and generate comprehensive frequency distribution from queue data.

# Examples
# Input:

# [1, 2, 2, 3, 1, 1]
# Output:

# {1: 3, 2: 2, 3: 1}
# Input:

# [5, 5, 7, 8, 7]
# Output:

# {5: 2, 7: 2, 8: 1}
from queue import Queue

def count_occurrences(q: Queue) -> dict:
    freq = {}
    temp = Queue()

    # Count occurrences
    while not q.empty():
        item = q.get()
        freq[item] = freq.get(item, 0) + 1
        temp.put(item)

    while not temp.empty():
        q.put(temp.get())

    return freq