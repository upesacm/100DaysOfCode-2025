def min_platforms(arr, dep):
    arr.sort()
    dep.sort()
    n = len(arr)
    i = j = 0
    plat = res = 0
    while i < n and j < n:
        if arr[i] <= dep[j]:
            plat += 1
            res = max(res, plat)
            i += 1
        else:
            plat -= 1
            j += 1
    return res

print(min_platforms([900, 940, 950, 1100, 1500, 1800], [910, 1200, 1120, 1130, 1900, 2000]))
print(min_platforms([100, 200, 300], [150, 250, 350]))
