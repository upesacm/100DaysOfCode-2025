def max_consecutive_ones(array):
    maximum_ones = 0  # Initializing maximum number of ones with a very large number
    current_ones = 0
    for num in array:
        if num == 1:
            current_ones += 1
        else:
            if current_ones > maximum_ones:
                maximum_ones = current_ones
                current_ones = 0

    if current_ones > maximum_ones:
        maximum_ones = current_ones
        
    return maximum_ones

try:
    array = list(map(int, input("Enter the elements of the array : ").split()))
    print(max_consecutive_ones(array))
except:
    print("Invalid input. Please try with a valid input.")
