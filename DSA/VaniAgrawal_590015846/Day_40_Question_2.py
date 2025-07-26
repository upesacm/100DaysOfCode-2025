#Implement a monotonic stack solution to find the maximum rectangular area by tracking height boundaries and computing optimal width extensions.

heights = list(map(int, input("Enter histogram bar heights separated by commas: ").split(',')))

heights.append(0)

stack = []
max_area = 0

for i in range(len(heights)):
    while stack and heights[i] < heights[stack[-1]]:
        height = heights[stack.pop()]
        width = i if not stack else i - stack[-1] - 1
        area = height * width
        if area > max_area:
            max_area = area
    stack.append(i)

print("Maximum rectangular area:", max_area)
