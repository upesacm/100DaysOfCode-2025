# Implement two-pointer convergence on sorted arrays to efficiently detect pairs with target sums using optimal time complexity.
arr = list(map(int, input("Enter array elements separated by spaces: ").split()))
x = int(input("Enter target sum x: "))

arr.sort()

left = 0
right = len(arr) - 1
found = False

while left < right:
    current_sum = arr[left] + arr[right]
    if current_sum == x:
        found = True
        break
    elif current_sum < x:
        left += 1
    else:
        right -= 1

print("true" if found else "false")
