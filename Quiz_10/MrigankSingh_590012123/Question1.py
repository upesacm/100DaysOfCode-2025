def activity_selection(start, end):
    n = len(start)
    activities = []

    for i in range(n):
        activities.append((start[i], end[i], i))

    # BUG FIXED: Changed sorting criteria from start time to end time
    # Original bug: activities.sort(key=lambda x: x[0]) - sorted by start time
    # Why the bug caused suboptimal results:
    #   Sorting by start time may select activities that start early but have long durations,
    #   preventing the selection of multiple activities that could fit in the same time frame.
    #   The optimal strategy is to select activities that finish earliest, maximizing the remaining time for more activities.
    activities.sort(key=lambda x: x[1])  # Correct: sort by end time

    selected = [activities[0]]
    last_end = activities[0][1]

    for i in range(1, n):
        if activities[i][0] >= last_end:
            selected.append(activities[i])
            last_end = activities[i][1]

    return len(selected)


# Test case:
start = [1, 3, 0, 5, 8, 5]
end = [2, 4, 6, 7, 9, 9]
result = activity_selection(start, end)
print(f"Maximum activities: {result}")  # Expected: 4
