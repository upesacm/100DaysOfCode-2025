
#xor_sum is the XOR of the two unique numbers: a ^ b.

#You should not group elements using xor_sum because it's a mix of both unique numbers.

#Instead, you should group numbers using a bit where a and b differ, which is stored in diff_bit.

def find_unique_pair(arr):
    xor_sum = 0
    # Step 1: XOR all elements to get xor of the two unique numbers
    for num in arr:
        xor_sum ^= num

    # Step 2: Isolate the rightmost set bit where the two unique numbers differ
    diff_bit = xor_sum & -xor_sum

    unique1 = 0
    unique2 = 0

    # Step 3: Divide numbers into two groups based on diff_bit and XOR within each group
    for num in arr:
        if num & diff_bit:
            unique1 ^= num
        else:
            unique2 ^= num

    return unique1, unique2

# Main method
if __name__ == "__main__":
    # Taking input from the user
    input_str = input("Enter array elements separated by spaces: ")
    arr = list(map(int, input_str.strip().split()))

    result = find_unique_pair(arr)
    print(result)
