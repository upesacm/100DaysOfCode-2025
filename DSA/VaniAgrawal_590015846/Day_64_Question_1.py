# Implement greedy activity selection using earliest finish time strategy to maximize non-overlapping activity participation with optimal scheduling.
def max_activities(start, end):
    activities = sorted(zip(start, end), key=lambda x: x[1])
    count, last_end = 0, -1
    for s, e in activities:
        if s >= last_end:
            count += 1
            last_end = e
    return count

start = list(map(int, input("Enter start times: ").split()))
end = list(map(int, input("Enter end times: ").split()))
print(max_activities(start, end))
