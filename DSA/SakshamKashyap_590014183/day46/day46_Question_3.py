def merge_queues(q1, q2):

    # Create a copy of q1 to avoid modifying the original
    merged = list(q1)
    # Append elements of q2 in order
    for item in q2:
        merged.append(item)
    return merged

# Example Usage
Q1 = [1, 2]
Q2 = [3, 4]
print(merge_queues(Q1, Q2))  # Output: [1, 2, 3, 4]

Q1 = [5]
Q2 = [6, 7]
print(merge_queues(Q1, Q2))  # Output: [5, 6, 7]
