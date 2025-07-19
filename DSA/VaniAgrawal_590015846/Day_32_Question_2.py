# Find the Only Non-Repeating Element 

arr = list(map(int, input("Enter numbers separated by space: ").split()))
result = 0
for num in arr:
    result ^= num

print("Non-repeating element:", result)
