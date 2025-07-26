def findLargestRectangle(heights):
    if len(heights) == 0:
        return 0

    heights.append(0)
    stack = []
    maxArea = 0

    for i in range(len(heights)):
        while len(stack) > 0 and heights[i] < heights[stack[-1]]:
            topIndex = stack.pop()
            height = heights[topIndex]

            if len(stack) == 0:
                width = i
            else:
                width = i - stack[-1] - 1

            area = height * width
            if area > maxArea:
                maxArea = area

        stack.append(i)

    heights.pop()
    return maxArea
