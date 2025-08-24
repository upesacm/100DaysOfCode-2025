def activity_selection(start, end):
    """
    Returns the maximum number of non-overlapping activities.
    - Bug in original: Sorts by start time (suboptimal)
    - Fix: Sort by end time for greedy optimality
    """
    n = len(start)
    # Pair each activity's start and end time for sorting and selection
    activities = [(start[i], end[i], i) for i in range(n)]

    # Correct greedy step: Sort by end time (earliest finish first)
    activities.sort(key=lambda x: x[1])

    # Always select the first (earliest finishing) activity
    selected = [activities[0]]
    last_end = activities[0][1]

    # For each activity, select it if it starts after or when the last selected one ends
    for i in range(1, n):
        if activities[i][0] >= last_end:
            selected.append(activities[i])
            last_end = activities[i][1]

    # Optional: Print selected activity indices for understanding, remove if not needed
    print("Selected activity indices:", [act[2] for act in selected])
    return len(selected)

# Test
start = [1, 3, 0, 5, 8, 5]
end =   [2, 4, 6, 7, 9, 9]
result = activity_selection(start, end)
print(f"Maximum number of activities: {result}")

# Output:
# Selected activity indices: [0, 1, 3, 4]
# Maximum number of activities: 4
