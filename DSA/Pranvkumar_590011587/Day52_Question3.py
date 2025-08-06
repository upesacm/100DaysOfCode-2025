def trap_rain_water(height):
    if not height: return 0
    left, right = 0, len(height) - 1
    max_left, max_right = height[left], height[right]
    trapped = 0
    while left < right:
        if max_left < max_right:
            left += 1
            max_left = max(max_left, height[left])
            trapped += max(0, max_left - height[left])
        else:
            right -= 1
            max_right = max(max_right, height[right])
            trapped += max(0, max_right - height[right])
    return trapped

# Example usage:
print(trap_rain_water([0,1,0,2,1,0,1,3,2,1,2,1]))   
print(trap_rain_water([4,2,0,3,2,5]))             