def subarray_with_given_sum(arr, target):
    start = 0
    curr_sum = 0

    for end in range(len(arr)):
        curr_sum += arr[end]

        # Shrink the window as long as the sum is greater than the target
        while curr_sum > target and start <= end:
            curr_sum -= arr[start]
            start += 1

        # Check if we found the target sum
        if curr_sum == target:
            return f"Subarray found from index {start} to {end}"
    
    print("No subarray found with the given sum.")

array = list(map(int, input("Enter the elements of the array : ").split()))
target = int(input("Enter the value of target sum : "))
print(subarray_with_given_sum(array, target))
