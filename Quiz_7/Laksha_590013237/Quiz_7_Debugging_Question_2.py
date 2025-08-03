#problematic question 
#while q1 or q2:
  #  if q1:
    #    result.append(q1.popleft())
 #   if q2:
    #    result.append(q2.popleft())

#answer 2 
#When one queue is shorter, the rest of the longer queue is appended without maintaining alternation, which may break the intended pattern of alternating elements.

#corrected code
from collections import deque

def merge_queues_alternately(q1, q2):
    result = deque()
    while q1 and q2:
        result.append(q1.popleft())
        result.append(q2.popleft())
    while q1:
        result.append(q1.popleft())
    while q2:
        result.append(q2.popleft())
    return result
