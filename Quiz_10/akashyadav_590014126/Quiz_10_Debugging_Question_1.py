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

#The bug was sorting by start time instead of finish time.
#If we sort by start time, we may pick a longer activity early and block many smaller activities later.