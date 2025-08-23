def minimum_jumps(arr):
    n = len(arr)
    if n <= 1:
        return 0
    if arr[0] == 0:
        return -1  # Can't move anywhere
    
    jumps = 1
    maxReach = arr[0]
    steps = arr[0]

    for i in range(1, n):
        if i == n - 1:
            return jumps
        
        maxReach = max(maxReach, i + arr[i])
        steps -= 1

        if steps == 0:
            jumps += 1
            if i >= maxReach:
                return -1    # Can't move further
            steps = maxReach - i

    return jumps

try:
    arr = list(map(int, input("Enter the elements of the arr separated by spaces : ").split()))
    print(minimum_jumps(arr))
except:
    print("Invalid input. Please try with a valid input.")
