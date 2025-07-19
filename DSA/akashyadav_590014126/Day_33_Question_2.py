def turn_rightmost_zero(a):
    return (a & (a-1))

#example
print(turn_rightmost_zero(12))