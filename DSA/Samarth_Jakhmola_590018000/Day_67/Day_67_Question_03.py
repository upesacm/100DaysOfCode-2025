def non_overlapping_meetings(start, end):
    n = len(start)

    # Pair start and end time of each meeting
    meetings = list(zip(start, end))

    # Sort by the end time of each meeting
    meetings.sort(key = lambda x : x[1])

    count = 0
    last_end = -1

    for s, e in meetings:
        if s >= last_end:   # Checking the non-overlapping condition
            last_end = e
            count += 1

    return count

try:
    start = list(map(int, input("Enter the start time of the meetings, separated by spaces : ").split()))
    end = list(map(int, input("Enter the end time of the meetings, separated by spaces : ").split()))
    print(non_overlapping_meetings(start, end))
except:
    print("Invalid input. Please try with a valid input.")
