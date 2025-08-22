arr = list(map(int, input("Enter The array").split()))
x = int(input("Enter The number to be checked: "))
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
#for example:
#input : arr= [1, 2, 3, 4, 5], x = 6
#output : true