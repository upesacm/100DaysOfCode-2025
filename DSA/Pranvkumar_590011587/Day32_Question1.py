def swap_numbers(a, b):
    """
    Swaps the values of two integers using bitwise XOR without a temporary variable.

    The logic relies on the properties of XOR:
    1. x ^ x = 0 (XORing a number with itself results in 0)
    2. x ^ 0 = x (XORing a number with 0 results in the number itself)
    3. x ^ y = y ^ x (Commutative property)
    4. (x ^ y) ^ z = x ^ (y ^ z) (Associative property)

    Args:
        a (int): The first integer.
        b (int): The second integer.

    Returns:
        tuple: A tuple containing the swapped values of a and b.
    """
    print(f"Original values: a = {a}, b = {b}")
    a = a ^ b
    b = a ^ b
    a = a ^ b
    
    print(f"Swapped values:  a = {a}, b = {b}")
    return a, b

if __name__ == "__main__":
    # Input 1
    swap_numbers(4, 7)
    # Input 2
    swap_numbers(1, 2)