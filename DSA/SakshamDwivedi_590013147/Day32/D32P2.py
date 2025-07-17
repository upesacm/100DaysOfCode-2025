#Solution Function
def non_repeating(arr):
    result = 0
    for i in range(len(arr)):
        result = result ^ arr[i]
    return result

#Fixed Input
print(non_repeating([2,3,2]))

#Custom Input
arr = list(int(x) for x in input("Enter the array : ").split())
print(non_repeating(arr))
