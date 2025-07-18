def find_unique_element(arr):
    if not arr:
        print("Array is empty.")
        return None

    result = 0
    for num in arr:
        result ^= num

    print(f"The unique non-repeating element is: {result}")
    return result

arr = list(map(int, input("Enter the array elements separated by space: ").split()))
find_unique_element(arr)
