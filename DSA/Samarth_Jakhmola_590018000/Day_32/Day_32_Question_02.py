def find_non_repeating_element(array):
    result = 0
    for i in array:
        result ^= i
    return result

try:
    array = list(map(int, input("Enter the elements of the array separated by spaces : ").split()))
    print(find_non_repeating_element(array))
except:
    print("Invalid input. Please try with a valid input.")
