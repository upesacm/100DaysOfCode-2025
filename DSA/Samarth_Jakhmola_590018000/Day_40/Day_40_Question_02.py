def largest_rectangle(heights):
    stack = []
    max_area = 0
    heights.append(0)

    for i, h in enumerate(heights):
        while stack and heights[stack[-1]] > h:
            height = heights[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            area = height * width
            max_area = max(max_area, area)
        stack.append(i)

    return max_area

try:
    heights = list(map(int, input("Enter histogram heigts separated by spaces : ").split()))
    print(largest_rectangle(heights))
except:
    print("Invalid input. Please try with a valid input.")
