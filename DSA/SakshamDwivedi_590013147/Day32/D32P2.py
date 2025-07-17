#Solution Function
def non_repeating(arr):
    current_xor = 0
    for i in range(len(arr)):
        current_xor = current_xor ^ arr[i]
    return current_xor

#Fixed Input
print(non_repeating([2,3,2]))

#Custom Input
arr = list(int(x) for x in input("Enter the array : ").split())
print(non_repeating(arr))
