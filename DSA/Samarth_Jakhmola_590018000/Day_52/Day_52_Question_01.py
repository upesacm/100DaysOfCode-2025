def pair_sum(array, x):
    # Initializing the pointers
    left = 0
    right = left + 1

    while right < len(array):
        curr_sum = array[left] + array[right]
        if curr_sum == x:
            return True
        else:
            left += 1
            right = left + 1

    return False
    
try:
    array = list(map(int, input("Enter the elements of the array : ").split()))
    x = int(input("Enter the value of x : "))
    print("true" if pair_sum(array, x) else "false")
except:
    print("Invalid input. Please try with a valid input.")
