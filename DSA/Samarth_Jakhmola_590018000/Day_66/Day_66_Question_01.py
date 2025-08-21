def min_platforms(arr, dep):
    n = len(arr)
    arr.sort()
    dep.sort()

    i = j = 0
    platforms = max_platforms = 0

    while i < n and j < n:
        if arr[i] <= dep[j]:
            platforms += 1    # Train arrives
            max_platforms = max(max_platforms, platforms)
            i += 1
        else:
            platforms -= 1     # Train departs
            j += 1

    return max_platforms

try:
    arr = list(map(int, input("Enter the arrival times of the trains separated by spaces : ").split()))
    dep = list(map(int, input("Enter the end times of the activities separated by spaces : ").split()))
    print(min_platforms(arr, dep))
except:
    print("Invalid input. Please try with a valid input.")
