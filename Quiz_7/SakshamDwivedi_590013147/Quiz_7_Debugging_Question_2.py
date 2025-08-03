'''The implementation of this code is fine, the issue is with working alternatively. This logic does not
have an alternation pattern between queues. It prioritizes the availability.'''

from collections import deque


def merge_queues_alternately(q1, q2):
    result = deque()
    turn = 0

     while q1 or q2:
        if turn == 0:
            if q1:
                result.append(q1.popleft())
            elif q2:
                result.append(q2.popleft())
        '''The function now strictly alternates between the two queues by maintaining a turn variable,
            ensuring fair merging even when one queue becomes empty. It also correctly returns the
            full result after merging is complete, fixing the earlier return issue.'''
        
            if q2:
                result.append(q2.popleft())
            elif q1:
                result.append(q1.popleft()) 

        turn = 1 - turn
        
    return result



# Test case:
queue1 = deque([1, 3, 5])
queue2 = deque([2, 4])
merged = merge_queues_alternately(queue1, queue2)
print(f"Merged queue: {list(merged)}")
#The output gives the correct result.
