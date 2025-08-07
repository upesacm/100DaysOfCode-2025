def trap_rain_water(heights):
    left = 0
    right = len(heights) - 1

    max_left = 0
    max_right = 0

    total_water = 0

    while left < right:
        if heights[left] < heights[right]:
            if heights[left] >= max_left:
                max_left = heights[left]
            else:
                total_water += max_left - heights[left]
            left += 1
        else:
            if heights[right] >= max_right:
                max_right = heights[right]
            else:
                total_water += max_right - heights[right]
            right -= 1

    return total_water
