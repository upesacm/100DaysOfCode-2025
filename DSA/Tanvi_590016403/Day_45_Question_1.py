from collections import deque
import copy

# 1. Sum of elements in a queue
def sum_of_queue(queue):
    temp_queue = copy.deepcopy(queue)
    total = 0
    while temp_queue:
        total += temp_queue.popleft()
    return total

# 2. Compare two queues
def are_queues_equal(q1, q2):
    temp_q1 = copy.deepcopy(q1)
    temp_q2 = copy.deepcopy(q2)

    if len(temp_q1) != len(temp_q2):
        return "No"
    
    while temp_q1 and temp_q2:
        if temp_q1.popleft() != temp_q2.popleft():
            return "No"
    return "Yes"

# 3. Find maximum element in a queue
def max_in_queue(queue):
    temp_queue = copy.deepcopy(queue)
    if not temp_queue:
        return None  # or raise an exception if queue is empty
    max_val = temp_queue.popleft()
    while temp_queue:
        val = temp_queue.popleft()
        if val > max_val:
            max_val = val
    return max_val

# Example usage
Q1 = deque([1, 2, 3])
Q2 = deque([1, 2, 3])
Q3 = deque([3, 5, 1, 2])

print("Sum of Q1:", sum_of_queue(Q1))            # Output: 6
print("Are Q1 and Q2 equal?", are_queues_equal(Q1, Q2))  # Output: Yes
print("Max in Q3:", max_in_queue(Q3))            # Output: 5
