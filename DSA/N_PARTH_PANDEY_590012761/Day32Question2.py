def find_non_repeating(arr):
    result = 0
    for num in arr:
        result ^= num
    return result
input_str = input("Enter the array elements separated by spaces: ")
arr = list(map(int, input_str.split()))
non_repeating = find_non_repeating(arr)
print(f"The non-repeating element is: {non_repeating}")