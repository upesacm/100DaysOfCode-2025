def find_min_platform(arr,dep):
    n=len(arr)
    arr.sort()
    dep.sort()

    platform_needed=0
    max_platforms=0
    i=j=0

    while i<n and j<n:
        if arr[i] <= dep[j]:
            plarfoem_needed += 1
            max_platforms=max(max_platforms,platform_needed)
            i += 1
        else:
            platform_needed -= 1
            j += 1
    
    return max_platforms