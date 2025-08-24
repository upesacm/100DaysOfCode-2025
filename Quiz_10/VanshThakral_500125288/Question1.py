
# Bug in sorting criteria:
# activities.sort(key=lambda x: x[0])

# Why this causes suboptimal results:

# The greedy strategy in the Activity Selection problem requires choosing the activity that finishes earliest, so that maximum remaining time is left for other activities.

# Sorting by start time might select a long activity that blocks many shorter ones later, producing fewer activities in the result.

# Correct Fix
 activities.sort(key=lambda x: x[1]) # sort by end time
