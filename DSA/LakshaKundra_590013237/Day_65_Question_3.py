def min_removals(intervals):
    intervals.sort(key=lambda x: x[1])
    count, last_end = 0, float('-inf')
    for s, e in intervals:
        if s >= last_end:
            count += 1
            last_end = e
    return len(intervals) - count, count

print(min_removals([(1, 2), (2, 3), (3, 4), (1, 3)]))
print(min_removals([(1, 2), (1, 2), (1, 2)]))
