'''1.bug in
   if q1:
       result.append(q1.popleft())
   if q2:
       result.append(q2.popleft())
2.The issue arises because the function checks if q1 and q2 are non-empty separately. 
If one queue is empty and the other is not, the loop will continue to run, but it will only append elements 
from the non-empty queue. This results in the merged queue not being truly alternating when one queue is shorter
 than the other.

 correct code:'''
from collections import deque
def merge_queues_alternately(q1, q2):
    result = deque()
    while q1 and q2:
        result.append(q1.popleft())
        result.append(q2.popleft())
    result.extend(q1)
    result.extend(q2)
    return result
queue1 = deque([1, 3, 5])
queue2 = deque([2, 4])
merged = merge_queues_alternately(queue1, queue2)
print(list(merged))
