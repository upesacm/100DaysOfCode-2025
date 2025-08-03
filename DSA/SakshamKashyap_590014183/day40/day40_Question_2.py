def largest_rectangle_area(heights):
    """
    Finds the largest rectangle in a histogram.
    """
    stack = []  # Will store pairs of (index, height)
    max_area = 0
    
    for i, h in enumerate(heights):
        start_index = i
        # If the current bar is shorter than the bar at the top of the stack,
        # we need to pop from the stack and calculate areas.
        while stack and stack[-1][1] > h:
            index, height = stack.pop()
            # Calculate the area of the rectangle ending at the popped bar
            width = i - index
            max_area = max(max_area, height * width)
            # The current bar can extend back to the index of the popped bar
            start_index = index
        
        stack.append((start_index, h))

    # After iterating through all bars, calculate areas for any remaining bars in the stack
    for i, h in stack:
        # These rectangles extend all the way to the end of the histogram
        width = len(heights) - i
        max_area = max(max_area, h * width)
        
    return max_area

# Test cases
print(largest_rectangle_area([2, 1, 5, 6, 2, 3]))
print(largest_rectangle_area([2, 4]))
