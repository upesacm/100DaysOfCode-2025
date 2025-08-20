def min_removals_to_avoid_overlap(intervals):
    intervals.sort(key=lambda x: x[1])
    count = 0
    current_end = float('-inf')
    
    for start, end in intervals:
        if start >= current_end:
            count += 1
            current_end = end
    
    return len(intervals) - count 

# Example
print(min_removals_to_avoid_overlap([(1, 2), (1, 2), (1, 2)]))         