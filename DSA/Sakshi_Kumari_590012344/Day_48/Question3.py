from collections import deque

def count_frequencies(queue):
    frequency = {}
    for item in queue:
        if item in frequency:
            frequency[item] += 1
        else:
            frequency[item] = 1
    return frequency
