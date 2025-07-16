def check_for_power_2(n):
    return n>0 and (n & (n-1)) == 0

print(check_for_power_2(1024))