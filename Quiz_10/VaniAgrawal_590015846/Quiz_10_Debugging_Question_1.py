# question 1

def activity_selection(start, end):
    n = len(start)
    activities = []
    for i in range(n):
        activities.append((start[i], end[i], i))
    activities.sort(key=lambda x: x[1])
    selected = [activities[0]]
    last_end = activities[0][1]
    for i in range(1, n):
        if activities[i][0] >= last_end:
            selected.append(activities[i])
            last_end = activities[i][1]
    return len(selected)


start = [1, 3, 0, 5, 8, 5]
end = [2, 4, 6, 7, 9, 9]
result = activity_selection(start, end)
print(f"Maximum activities: {result}")


# The bug is in sorting by start time instead of end time.

# Sorting by start time leads to suboptimal results because we may select an early activity that blocks others with shorter finish times.
