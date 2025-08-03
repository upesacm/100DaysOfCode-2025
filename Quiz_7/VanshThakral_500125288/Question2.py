# Error in line

 # while q1 or q2:       # (Line 8)
     # if q1:            # (Line 9)
    #    result.append(q1.popleft())
    # if q2:            # (Line 11)
      #  result.append(q2.popleft())

# Why This Causes Incorrect Behavior
 # Line 8 (while q1 or q2)

# This allows the loop to continue even after one queue is empty, so remaining elements from the longer queue are appended consecutively, breaking the strict alternation pattern.

# Lines 9 & 11 (if q1 / if q2)

# These if statements are not synchronized with alternation logic.

# Once one queue is empty, the loop keeps taking from the other queue in a row, effectively failing the alternate merge after that point.

from collections import deque

def merge_queues_alternately(q1, q2):
    result = deque()
    turn = 0  

    while q1 or q2:
        if turn == 0 and q1:
            result.append(q1.popleft())
        elif turn == 1 and q2:
            result.append(q2.popleft())
        

        turn = 1 - turn

        if not q1:
            turn = 1
        if not q2:
            turn = 0

    return result


queue1 = deque([1, 3, 5])
queue2 = deque([2, 4])
merged = merge_queues_alternately(queue1, queue2)
print(f"Merged queue: {list(merged)}")  

queue3 = deque([10, 20, 30, 40])
queue4 = deque([1])
merged2 = merge_queues_alternately(queue3, queue4)
print(f"Merged queue: {list(merged2)}")  
