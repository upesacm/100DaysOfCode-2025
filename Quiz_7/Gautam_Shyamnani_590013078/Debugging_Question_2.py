from collections import deque

def merge_queues_alternately(q1, q2):
    result = deque()
    len1, len2 = len(q1), len(q2)
    max_len = max(len1, len2)

    for i in range(max_len):
        if i < len1:
            result.append(q1[i])
        if i < len2:
            result.append(q2[i])

    return result
