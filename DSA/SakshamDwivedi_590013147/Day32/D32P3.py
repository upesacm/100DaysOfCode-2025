#Solution Function
def xor_all(arr):
    final_xor = 0
    for i in arr:
        final_xor ^= i
    return final_xor

#Fixed Input
print(xor_all([1, 2, 3]))

#Custom Input
arr = list(int(x) for x in input("Enter the array : ").split())
print(xor_all(arr))
