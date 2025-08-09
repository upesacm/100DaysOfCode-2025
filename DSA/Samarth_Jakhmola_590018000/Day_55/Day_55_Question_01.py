def longest_subarray(arr, k):
    prefix_sum = 0
    prefix_map = {} # Stores prefix_sum : first index
    max_length = 0

    for i, num in enumerate(arr):
        prefix_sum += num

        # Case 1 : If prefix_sum itself is equal to k
        if prefix_sum == k:
            max_length = i + 1

        # Case 2 : If (prefix_sum - k) seen before, subarray sum = k
        if (prefix_sum - k) in prefix_map:
            max_length = max(max_length, i - prefix_map[prefix_sum - k])

        # Store prefix_sum if not seen before (keep earliest index)
        if prefix_sum not in prefix_map:
            prefix_map[prefix_sum] = i

    return max_length

try:
    arr = list(map(int, input("Enter the elements of the array : ").split()))
    k = int(input("Enter the value of k : "))
    print(longest_subarray(arr, k))
except:
    print("Invalid input. Please try with a valid input.")
