#1. Identify the bug in the sorting criteria 
#   -- activities.sort(key=lambda x: x[0]) 
#   --Bug: The activities are being sorted by start time, but the greedy algorithm requires sorting by end time.

#2. Why this causes suboptimal results
#   --Sorting by start time can lead to selecting activities that begin early but end late, blocking shorter activities that could have fit in between. This violates the greedy principle of choosing the activity that frees up time earliest, allowing more activities to follow.

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

    return len(selected)
