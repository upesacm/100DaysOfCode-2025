def is_power_of_two(n):
    return n > 0 and (n & (n - 1)) == 0

print("Yes" if is_power_of_two(8) else "No")
print("Yes" if is_power_of_two(10) else "No")

