def merge_queues_alternately(q1, q2):
    result = deque()
    
    # Alternate while both have elements
    while q1 and q2:
        result.append(q1.popleft())
        result.append(q2.popleft())
    
    # Drain remaining elements
    result.extend(q1)
    result.extend(q2)
    
    return result
