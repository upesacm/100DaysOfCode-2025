def find_non_repeating_element(nums):
    """
    Finds the single element in an array that does not repeat.
    Every other element appears exactly twice.

    The logic is that when we XOR all elements in the array, the pairs of
    identical numbers will cancel each other out (since x ^ x = 0). The
    only number remaining will be the unique, non-repeating element.

    Args:
        nums (list[int]): A list of integers.

    Returns:
        int: The unique non-repeating element in the list.
    """
    unique_element = 0
    for num in nums:
        unique_element ^= num
    return unique_element

if __name__ == "__main__":
    # Input 1
    arr1 = [2, 3, 2]
    result1 = find_non_repeating_element(arr1)
    print(f"Input: {arr1}")
    print(f"Output: {result1}")
    # Input 2
    arr2 = [5, 1, 1, 5, 7]
    result2 = find_non_repeating_element(arr2)
    print(f"Input: {arr2}")
    print(f"Output: {result2}")