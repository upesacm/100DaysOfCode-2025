# 1. Identify the bug in the sorting criteria:
#    The original code sorts activities by their start time (x[0]), but the correct greedy approach is to sort by end time (x[1]).
#
# 2. Why this causes suboptimal results:
#    Sorting by start time may select activities that start early but end late, blocking other activities that could have fit in the schedule. Sorting by end time ensures we always pick the activity that leaves the room free for the next earliest possible activity, maximizing the number of non-overlapping activities.

def activity_selection(start, end):
	n = len(start)
	activities = []
	for i in range(n):
		activities.append((start[i], end[i], i))
	# Corrected: sort by end time
	activities.sort(key=lambda x: x[1])
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
print(f"Maximum activities: {result}")
