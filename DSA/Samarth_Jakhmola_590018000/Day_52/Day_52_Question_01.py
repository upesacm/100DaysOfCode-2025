def pair_sum(array, x):
    # Sort the array (helps if it is not already sorted)
    array.sort()

    # Initializing the pointers
    left = 0
    right = len(array) - 1

    while left < right:
        curr_sum = array[left] + array[right]
        if curr_sum == x:
            return True
        elif curr_sum < x:
            left += 1
        else:
            right -= 1

    return False
    
try:
    array = list(map(int, input("Enter the elements of the array : ").split()))
    x = int(input("Enter the value of x : "))
    print("true" if pair_sum(array, x) else "false")
except:
    print("Invalid input. Please try with a valid input.")
