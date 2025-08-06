def trap_rain_water(height):
    if not height:
        return 0

    left, right = 0, len(height) - 1
    left_max, right_max = height[left], height[right]
    trapped_water = 0

    while left < right:
        if left_max < right_max:
            left += 1
            left_max = max(left_max, height[left])
            trapped_water += max(0, left_max - height[left])
        else:
            right -= 1
            right_max = max(right_max, height[right])
            trapped_water += max(0, right_max - height[right])

    return trapped_water

# Example usage:
height1 = [0,1,0,2,1,0,1,3,2,1,2,1]
print(trap_rain_water(height1))  # Output: 6

height2 = [4,2,0,3,2,5]
print(trap_rain_water(height2))  # Output: 9
