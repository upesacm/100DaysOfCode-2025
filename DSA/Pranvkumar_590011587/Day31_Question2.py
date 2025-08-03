def multiply_by_two(n: int) -> int:
    """
    Multiplies a number by 2 using the left bitwise shift operator.
    Shifting the bits of a number to the left by 1 is equivalent to multiplying it by 2.
    Example: 7 (0111) << 1 = 14 (1110)

    Args:
        n: The number to multiply.

    Returns:
        The result of n * 2.
    """
    return n << 1

if __name__ == "__main__":
    num1_mult = 3
    num2_mult = 7
    print(f"Input: n = {num1_mult}")
    print(f"Output: {multiply_by_two(num1_mult)}")
    print(f"Input: n = {num2_mult}")
    print(f"Output: {multiply_by_two(num2_mult)}") 