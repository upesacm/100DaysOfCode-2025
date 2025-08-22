def longest_mountain(array):
    n = len(array)
    max_len = 0
    i = 1  # Starting from 2nd element of the array

    while i < n - 1:
        # Checking whether the current element is a peak
        if array[i - 1] < array[i] > array[i + 1]:
            # Expand to the left
            left = i - 1
            while left > 0 and array[left - 1] < array[left]:
                left -= 1

            # Expand to the right
            right = i + 1
            while right < n - 1 and array[right] > array[right + 1]:
                right += 1

            # Calculate mountain length
            mountain_len = right - left + 1
            max_len = max(max_len, mountain_len)

            # Move i to the end of this mountain
            i = right
        else:
            i += 1  # Not a peak, just movev forward

    return max_len

try:
    array = list(map(int, input("Enter the elements of the array : ").split()))
    print(longest_mountain(array))
except:
    print("Invalid input. Please try with a valid input.")
