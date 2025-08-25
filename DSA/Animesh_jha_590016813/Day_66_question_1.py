def min_platforms(arr, dep):
    n = len(arr)
    arr.sort()
    dep.sort()
    
    i, j = 1, 0
    platforms_needed = 1
    max_platforms = 1
    
    while i < n and j < n:
        if arr[i] <= dep[j]:  
            platforms_needed += 1
            i += 1
            max_platforms = max(max_platforms, platforms_needed)
        else:  
            platforms_needed -= 1
            j += 1
    
    return max_platforms


print(min_platforms([900, 940, 950, 1100, 1500, 1800],
                    [910, 1200, 1120, 1130, 1900, 2000]))
print(min_platforms([100, 200, 300], [150, 250, 350]))  
