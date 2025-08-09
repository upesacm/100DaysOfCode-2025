#Implement two-pointer convergence with height-based movement strategy to find maximum water container area through optimal boundary selection.
height = list(map(int, input("Enter heights separated by spaces: ").split()))
left = 0
right = len(height) - 1
max_area = 0

while left < right:
    area = min(height[left], height[right]) * (right - left)
    max_area = max(max_area, area)
    if height[left] < height[right]:
        left += 1
    else:
        right -= 1

print("Output:", max_area)
