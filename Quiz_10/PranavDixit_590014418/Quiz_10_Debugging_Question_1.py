def activity_selection(start, end):
    n = len(start)
    activities = []

    for i in range(n):
        activities.append((start[i], end[i], i))

    # ---- BUG FIX ----
    # Earlier the code was sorting by start time (x[0]),
    # but in activity selection problem we need to sort
    # by the END time (x[1]) so that we always pick the
    # activity which finishes earliest.
    activities.sort(key=lambda x: x[1])

    selected = [activities[0]]
    last_end = activities[0][1]

    for i in range(1, n):
        if activities[i][0] >= last_end:
            selected.append(activities[i])
            last_end = activities[i][1]

    return len(selected), selected


# test case
start = [1, 3, 0, 5, 8, 5]
end = [2, 4, 6, 7, 9, 9]
result, selected_activities = activity_selection(start, end)

print("Maximum activities:", result)
print("Selected activities (start, end):", [(s, e) for s, e, _ in selected_activities])

"""
--------------------------
ANSWERS TO TASKS:

1) Bug in sorting criteria:
   -> I mistakenly sorted by start times. 
   -> It should be sorted by end times because greedy choice is 
      to finish as early as possible.

2) Why this gives wrong results:
   -> If we sort by start, we might pick a long activity that 
      blocks many smaller ones.
   -> Example: an activity starting early but ending late will
      stop us from picking other short ones, so we get fewer in total.
   -> Sorting by end times fixes this and ensures maximum activities.
--------------------------
"""
