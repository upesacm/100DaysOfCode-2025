from collections import deque

# Function 1: Find minimum element in a queue
def find_min_in_queue(q):
    min_val = float('inf')
    size = len(q)

    for _ in range(size):
        current = q.popleft()
        min_val = min(min_val, current)
        q.append(current)  # Restore original structure

    return min_val

# Function 2: Count even and odd numbers in a queue
def count_even_odd(q):
    even_count = 0
    odd_count = 0
    size = len(q)

    for _ in range(size):
        current = q.popleft()
        if current % 2 == 0:
            even_count += 1
        else:
            odd_count += 1
        q.append(current)  # Preserve order

    return even_count, odd_count

# Function 3: Merge two queues
def merge_queues(q1, q2):
    merged = deque(q1)   # Copy of first queue
    merged.extend(q2)    # Add all from second queue
    return merged

# Example Usage
if __name__ == "__main__":
    # Find minimum
    q_min = deque([4, 2, 7, 1])
    print("Minimum element in queue:", find_min_in_queue(q_min))  # Output: 1

    # Count even and odd
    q_count = deque([1, 2, 3, 4, 5])
    even, odd = count_even_odd(q_count)
    print(f"Even: {even}, Odd: {odd}")  # Output: Even: 2, Odd: 3

    # Merge two queues
    q1 = deque([1, 2])
    q2 = deque([3, 4])
    merged = merge_queues(q1, q2)
    print("Merged Queue:", list(merged))  # Output: [1, 2, 3, 4]
