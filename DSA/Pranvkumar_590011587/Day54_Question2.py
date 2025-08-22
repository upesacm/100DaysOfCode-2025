def max_area(height):
    left, right = 0, len(height)-1
    max_water = 0
    while left < right:
        h = min(height[left], height[right])
        w = right - left
        max_water = max(max_water, h*w)
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
    return max_water

# Example Usage
print(max_area([1,8,6,2,5,4,8,3,7]))   
print(max_area([1,1]))                 