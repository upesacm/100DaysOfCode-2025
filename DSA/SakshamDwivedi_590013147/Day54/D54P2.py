def max_area(height):
    left = 0
    right = len(height) - 1
    max_water = 0

    while left < right:
        h = min(height[left], height[right])
        w = right - left
        current_area = h * w
        max_water = max(max_water, current_area)
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1

    return max_water

#Fixed Input
height = [1,8,6,2,5,4,8,3,7]
print(max_area(height))
