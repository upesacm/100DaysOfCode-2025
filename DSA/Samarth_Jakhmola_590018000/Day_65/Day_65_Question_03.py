def schedule_non_overlapping_tasks(intervals):
    intervals.sort(key = lambda x : x[1])  # Sorting the tasks according to their end time starting with the earliest finishing

    kept = 1
    last_end = intervals[0][1]

    for i in range(1, len(intervals)):
        if intervals[i][0] >= last_end:
            kept += 1
            last_end = intervals[i][1]

    removed = len(intervals) - kept
    return f"Remove {removed} -> Remaining {kept}"

try:
    n = int(input("Enter the number of tasks : "))
    intervals = []
    print("Enter the start and end time of the tasks one at a time separated by spaces : ")
    for i in range(n):
        intervals.append(tuple(map(int, input().split())))
    print(schedule_non_overlapping_tasks(intervals))
except:
    print("Invalid input. Please try with a valid input.")
