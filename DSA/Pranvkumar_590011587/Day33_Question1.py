def have_opposite_signs(a, b):
    """
    Check if two numbers have opposite signs.
    Opposite signs mean a XOR b is negative.
    """
    return (a ^ b) < 0

print("1. Check if Two Numbers Have Opposite Signs")
print("Input: a = 2, b = -3 -> Output:", have_opposite_signs(2, -3)) 
print("Input: a = -4, b = -5 -> Output:", have_opposite_signs(-4, -5)) 