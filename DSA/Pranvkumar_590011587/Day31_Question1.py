def is_power_of_two(n: int) -> bool:
    """
    Checks if a number is a power of 2 using bitwise operations.
    A positive number is a power of 2 if it has only one bit set to 1 in its binary representation.
    The expression `n & (n - 1)` unsets the rightmost set bit.
    If the original number was a power of 2, it only had one set bit, so the result of the AND operation will be 0.
    We also check if n > 0 because 0 is not a power of 2.

    Args:
        n: The number to check.

    Returns:
        True if n is a power of 2, False otherwise.
    """
    if not isinstance(n, int) or n <= 0:
        return False
    return (n & (n - 1)) == 0

if __name__ == "__main__":
    num1_check = 8
    num2_check = 10
    print(f"Input: {num1_check}")
    print(f"Output: {'Yes' if is_power_of_two(num1_check) else 'No'}") 
    print(f"Input: {num2_check}")
    print(f"Output: {'Yes' if is_power_of_two(num2_check) else 'No'}") 