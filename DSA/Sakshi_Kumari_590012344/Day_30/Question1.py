Your task: Clear a specific bit position to 0 using bitwise operations while preserving all 
other bits.
def clear_bit(number, position):
    if not isinstance(number, int) or not isinstance(position, int):
        raise TypeError("Both number and position must be integers.")
    if position < 0:
        raise ValueError("Bit position must be non-negative.")
    if number == 0:
        return 0
    if position >= number.bit_length():
        return number
    return number & ~(1 << position)
