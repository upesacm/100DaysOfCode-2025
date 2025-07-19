def have_opposite_signs(a, b):
    return (a ^ b) < 0

print(have_opposite_signs(2, -3))
print(have_opposite_signs(-4, -5))
