def maxArea(height):
    l, r = 0, len(height)-1
    ans = 0
    while l < r:
        ans = max(ans, (r-l) * min(height[l], height[r]))
        if height[l] < height[r]:
            l += 1
        else:
            r -= 1
    return ans

print(maxArea([1,8,6,2,5,4,8,3,7]))
print(maxArea([1,1]))
