def activity_selection(start, end):
    n = len(start)
    activities = [(start[i], end[i], i) for i in range(n)]

    # Bug Fix: Original code sorted activities by start time.
    # Correct Approach: Sort by end time to apply the greedy strategy.
    activities.sort(key=lambda x: x[1])  # Sort by end time

    selected = [activities[0]]
    last_end = activities[0][1]

    for i in range(1, n):
        # Select activity if its start time is greater than or equal to last selected end time
        if activities[i][0] >= last_end:
            selected.append(activities[i])
            last_end = activities[i][1]

    return len(selected)


# Test case
start = [1, 3, 0, 5, 8, 5]
end = [2, 4, 6, 7, 9, 9]
result = activity_selection(start, end)
print(f"Maximum activities: {result}")
