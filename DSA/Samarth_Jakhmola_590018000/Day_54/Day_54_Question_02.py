def most_water(height):
    left = 0 
    right = len(height) - 1
    max_area = 0

    while left < right:
        # Calculate current area
        width = right - left
        current_height = min(height[left], height[right])
        area = width * current_height

        # Update max_area if current is larger
        max_area = max(max_area, area)

        # Move the pointer pointing to the shorter line
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1

    return max_area
    
try:
    height = list(map(int, input("Enter the values of height : ").split()))
    print(most_water(height))
except:
    print("Invalid input. Please try with a valid input.")
