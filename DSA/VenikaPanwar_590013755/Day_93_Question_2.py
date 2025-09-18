def max_subarray_sum(nums):
    """
    Finds maximum sum of any contiguous subarray using Kadane's algorithm.
    Time: O(n), Space: O(1)
    """
    if not nums:
        return 0
    
    current_sum = nums[0]
    max_sum = nums[0]
    
    for i in range(1, len(nums)):
        # Either extend current subarray or start new subarray from current element
        current_sum = max(nums[i], current_sum + nums[i])
        max_sum = max(max_sum, current_sum)
    
    return max_sum

def max_subarray_with_indices(nums):
    """
    Returns maximum sum along with start and end indices of the subarray.
    Time: O(n), Space: O(1)
    """
    if not nums:
        return 0, 0, 0
    
    current_sum = nums[0]
    max_sum = nums[0]
    start = 0
    end = 0
    temp_start = 0
    
    for i in range(1, len(nums)):
        if current_sum < 0:
            current_sum = nums[i]
            temp_start = i
        else:
            current_sum += nums[i]
        
        if current_sum > max_sum:
            max_sum = current_sum
            start = temp_start
            end = i
    
    return max_sum, start, end

if __name__ == "__main__":
    # Test cases
    arr1 = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(f"Max subarray sum for {arr1}: {max_subarray_sum(arr1)}")  # Output: 6
    
    arr2 = [1]
    print(f"Max subarray sum for {arr2}: {max_subarray_sum(arr2)}")  # Output: 1
    
    # Test with indices
    max_sum, start, end = max_subarray_with_indices(arr1)
    print(f"Max sum: {max_sum}, Subarray: {arr1[start:end+1]}")  # Output: Max sum: 6, Subarray: [4, -1, 2, 1]
    
    # Show step-by-step for arr1
    print("\nStep-by-step analysis:")
    current_sum = arr1[0]
    max_sum = arr1[0]
    print(f"Index 0: current_sum = {current_sum}, max_sum = {max_sum}")
    
    for i in range(1, len(arr1)):
        current_sum = max(arr1[i], current_sum + arr1[i])
        max_sum = max(max_sum, current_sum)
        print(f"Index {i}: current_sum = {current_sum}, max_sum = {max_sum}")