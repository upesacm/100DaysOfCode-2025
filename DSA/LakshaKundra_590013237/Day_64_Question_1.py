def max_activities(start, end):
    activities = sorted(zip(start, end), key=lambda x: x[1])
    count, last_end = 0, 0
    for s, e in activities:
        if s >= last_end:
            count += 1
            last_end = e
    return count

print(max_activities([1, 3, 0, 5, 8, 5], [2, 4, 6, 7, 9, 9]))
print(max_activities([1, 2, 3], [2, 3, 4]))
