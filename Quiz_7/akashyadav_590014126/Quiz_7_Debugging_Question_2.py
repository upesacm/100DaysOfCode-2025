def merge_queues_alternately(q1, q2):
    result = deque()

    # Strict alternation while both queues have elements
    while q1 and q2:
        result.append(q1.popleft())
        result.append(q2.popleft())

    # Drain remaining elements
    while q1:
        result.append(q1.popleft())
    while q2:
        result.append(q2.popleft())

    return result

#Earlier while loop for q1 and q2 was creating bugs
#during bug, The loop appends from q1 and then from q2 in each iteration unconditionally,which causes back-to-back inserts from the longer queue after the shorter one is exhausted.
#So the alternate pattern breaks once one of the queues runs out.