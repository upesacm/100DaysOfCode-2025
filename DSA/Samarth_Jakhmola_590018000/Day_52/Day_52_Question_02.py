def pairs_difference(arr, k):
    present = set(arr)
    pairs = []

    for num in arr:
        if num + k in present:
            pairs.append((num, num + k))
        if num - k in present:
            pairs.append((num, num - k))
        
    return pairs

try:
    arr = list(map(int, input("Enter the elements of the array : ").split()))
    k = int(input("Enter the value of k : "))
    print(pairs_difference(arr, k))
except:
    print("Invalid input. Please try with a valid input.")
