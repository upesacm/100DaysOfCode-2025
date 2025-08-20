def erase_overlap_intervals(intervals):
    intervals.sort(key=lambda x: x[1])  
    count = 0
    last_end = float('-inf')

    for s, e in intervals:
        if s >= last_end:
            count += 1
            last_end = e
    
    removals = len(intervals) - count
    return removals, count

print("Removals, Remaining:", erase_overlap_intervals([(1, 2), (2, 3), (3, 4), (1, 3)]))  
print("Removals, Remaining:", erase_overlap_intervals([(1, 2), (1, 2), (1, 2)]))       
