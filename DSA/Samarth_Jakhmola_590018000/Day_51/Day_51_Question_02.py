def smallest_subarray(array, x):
    n = len(array)
    min_len = n + 1  # A value larger than any possible subarray length
    start = end = 0
    curr_sum = 0

    while end < n:
        # Expand the window until the sum > x
        while curr_sum <= x and end < n:
            curr_sum += array[end]
            end += 1

        # Shrink the window to minimize length while sum > x
        while curr_sum > x and start < n:
            min_len = min(min_len, end - start)
            curr_sum -= array[start]
            start += 1

    # If no subarray was found, return 0
    return min_len if min_len <= n else 0

try:
    array = list(map(int, input("Enter the elements of the array : ").split()))
    x = int(input("Enter the value of x : "))
    print(smallest_subarray(array, x))
except:
    print("Invalid input. Please try with a valid input.")
