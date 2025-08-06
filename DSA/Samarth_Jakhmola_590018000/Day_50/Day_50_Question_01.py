def max_sum_subarray(array, k):
    if k > len(array):
        return None
    
    # Setting the initial window sum
    window_sum = sum(array[:k])
    max_sum = window_sum

    # Slide the window through the array
    for i in range(k, len(array)):
        window_sum += array[i] - array[i - k]  # Add the next element, remove first element of previous window
        max_sum = max(max_sum, window_sum)
    
    return max_sum

try:
    array = list(map(int, input("Enter the elements of the array : ").split()))
    k = int(input("Enter the value of k : "))
    print(max_sum_subarray(array, k))
except:
    print("Invalid input. Please try with a valid input.")
