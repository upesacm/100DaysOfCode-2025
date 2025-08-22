def largest_number(array):
    array = list(map(str, array))

    array.sort(key = lambda x : x*10, reverse = True)

    result = ''.join(array)
    return '0' if result[0] == '0' else result

try:
    array = list(map(int, input("Enter the elements of the array separated by spaces : ").split()))
    print(f"\"{largest_number(array)}\"")
except:
    print("Invalid input. Please try with a valid input.")
