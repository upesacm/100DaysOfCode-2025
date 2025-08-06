def water_trap(arr):
    n = len(arr)
    left = 0
    right = n - 1
    left_max = 0
    right_max = 0
    water = [0] * n

    while left <= right:
        if arr[left] <= arr[right]:
            if arr[left] >= left_max:
                left_max = arr[left]
            else:
                water[left] = left_max - arr[left]
            left += 1
        else:
            if arr[right] >= right_max:
                right_max = arr[right]
            else:
                water[right] = right_max - arr[right]
            right -= 1

    return sum(water)

#Fixed Input
print(water_trap([0,1,0,2,1,0,1,3,2,1,2,1]))
