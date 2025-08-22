from collections import deque

def merge_queues_alternately(q1, q2):
    result = deque()
    turn = 0
    
    while q1 or q2:
        if turn % 2 == 0: 
            if q1:
                result.append(q1.popleft())
            elif q2: 
                result.append(q2.popleft())
        else:
            if q2:
                result.append(q2.popleft())
            elif q1: 
                result.append(q1.popleft())
        turn += 1
    
    return result
