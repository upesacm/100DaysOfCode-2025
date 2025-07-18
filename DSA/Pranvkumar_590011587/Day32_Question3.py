def find_xor_of_array(nums):
    """
    Calculates the bitwise XOR sum of all elements in an array.

    Args:
        nums (list[int]): A list of integers.

    Returns:
        int: The result of XORing all elements together.
    """
    # Initialize result to 0.
    xor_sum = 0
    for num in nums:
        xor_sum ^= num
    return xor_sum

if __name__ == "__main__":
    # Input 1
    arr3 = [1, 2, 3]
    result3 = find_xor_of_array(arr3)
    print(f"Input: {arr3}")
    print(f"Output: {result3}")
    # Input 2
    arr4 = [4, 5, 6]
    result4 = find_xor_of_array(arr4)
    print(f"Input: {arr4}")
    print(f"Output: {result4}")