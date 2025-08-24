#this is the bug
#activities.sort(key=lambda x: x[0])  

#answer 2
#The greedy algorithm works by always selecting the activity that finishes earliest.
#Sorting by start time breaks this logic because an activity that starts earlier might also finish later, unnecessarily blocking shorter activities that could allow more selection.

#correct code
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

start = [10, 12, 20]
end = [20, 25, 30]
result = activity_selection(start, end)
print(f"Maximum activities: {result}")

start = [1, 2, 3, 4, 5]
end = [2, 3, 4, 5, 6]
result = activity_selection(start, end)
print(f"Maximum activities: {result}")
