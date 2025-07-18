
def have_opposite_signs(a, b):
    if a == 0 or b == 0:
        return False
    return (a ^ b) < 0
