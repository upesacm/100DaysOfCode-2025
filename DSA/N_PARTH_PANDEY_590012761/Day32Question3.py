def xor_of_array(arr):
    result = 0
    for num in arr:
        result ^= num
    return result
input_str = input("Enter numbers separated by spaces: ")
arr = list(map(int, input_str.split()))
xor_result = xor_of_array(arr)
print(f"XOR of all numbers: {xor_result}")