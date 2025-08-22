from collections import deque

def has_all_unique(queue):
    seen = set()
    for item in queue:
        if item in seen:
            return False
        seen.add(item)
    return True
