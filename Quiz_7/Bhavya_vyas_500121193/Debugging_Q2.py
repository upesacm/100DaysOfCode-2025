def merge_queues_alternately(q1, q2):
    result = deque()
    temp_q1 = q1.copy()
    temp_q2 = q2.copy()

    while temp_q1 or temp_q2:
        if temp_q1:
            result.append(temp_q1.popleft())
        if temp_q2:
            result.append(temp_q2.popleft())

    return result
