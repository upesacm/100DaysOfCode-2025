def find_pairs_with_difference(arr, k):
    seen = set(arr)
    pairs = []
    for num in arr:
        if num + k in seen:
            pairs.append((num, num + k))
        if num - k in seen:
            pairs.append((num, num - k))
    return pairs

def main():
    n = int(input("Enter size of array: "))
    arr = list(map(int, input("Enter array elements: ").split()))
    k = int(input("Enter difference value k: "))
    result = find_pairs_with_difference(arr, k)
    print("Pairs with difference", k, ":")
    for pair in result:
        print(pair)

if __name__ == "__main__":
    main()
