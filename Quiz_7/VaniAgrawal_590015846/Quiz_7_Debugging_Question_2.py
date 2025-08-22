# Problematic lines:
# while q1 or q2:
#     if q1:
#         result.append(q1.popleft())
#     if q2:
#         result.append(q2.popleft())


#  Why this causes incorrect behavior:

# This logic does not truly alternate between queues.
# When one queue is exhausted, all remaining elements of the other queue are added in sequence without alternation.
# This violates the intended behavior of taking one element at a time in turn.

#correct code :
def merge_queues_alternately(q1, q2):
    result = deque()
    turn = 0  # 0 for q1, 1 for q2

    while q1 or q2:
        if turn == 0 and q1:
            result.append(q1.popleft())
        elif turn == 1 and q2:
            result.append(q2.popleft())

        if q1 and q2:
            turn = 1 - turn
        elif q1:
            turn = 0
        elif q2:
            turn = 1

    return result
