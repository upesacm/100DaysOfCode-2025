def max_activities(start, end):
    if len(start) != len(end):
        return 0
    
    # Combine start and end into activities and sort by end time
    activities = sorted(zip(start, end), key=lambda x: x[1])
    
    count = 0
    last_end = -1  # No initial end time
    
    for s, e in activities:
        if s >= last_end:
            count += 1
            last_end = e
    
    return count

# Example 1
start = [1, 3, 0, 5, 8, 5]
end = [2, 4, 6, 7, 9, 9]
print(max_activities(start, end))  # Output: 4

# Example 2
start = [1, 2, 3]
end = [2, 3, 4]
print(max_activities(start, end))  # Output: 3
