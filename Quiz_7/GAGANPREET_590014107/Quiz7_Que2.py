# 1. Identify the specific line(s) causing the bug 
# -- while q1 or q2:
#    if q1:
#       result.append(q1.popleft())
#    if q2:
#        result.append(q2.popleft())

#2. Why this causes incorrect behavior
#-- The logic does not alternate properly between the two queues.
#   Instead, it always appends from q1 first, then from q2, regardless of previous turns.
#   This results in a non-alternating merge when the queues are of unequal length

def merge_queues_alternately(q1, q2):
    result = deque()
    turn = 0  

    while q1 or q2:
        if turn == 0 and q1:
            result.append(q1.popleft())
        elif turn == 1 and q2:
            result.append(q2.popleft())
        turn = 1 - turn  

    return result
