def maximum_activities(start, end):
    n = len(start)

    # Pair start and end time of each activity
    activities = list(zip(start, end))

    # Sort by the end time of each activity
    activities.sort(key = lambda x : x[1])

    count = 0
    last_end = -1

    for s, e in activities:
        if s >= last_end:  # Checks the non - overlapping condition
            last_end = e
            count += 1

    return count

try:
    start = list(map(int, input("Enter the start times of the activities separated by spaces : ").split()))
    end = list(map(int, input("Enter the end times of the activities separated by spaces : ").split()))
    print(maximum_activities(start, end))
except:
    print("Invalid input. Please try with a valid input.")
