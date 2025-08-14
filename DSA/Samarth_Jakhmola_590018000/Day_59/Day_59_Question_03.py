def heap_type(arr):
    n = len(arr)
    for i in range(n // 2):
        left = 2 * i + 1
        right = 2 * i + 2
        if left < n and arr[i] != arr[left]:
            return "max" if arr[i] > arr[left] else "min"
        if right < n and arr[i] != arr[right]:
            return "max" if arr[i] > arr[right] else "min"
    return "unknown"   # All the elements are equal.

def valid_heap(arr, heap_type):
    n = len(arr)
    if heap_type == "unknown":
        return True
    if heap_type == "max":
        for i in range(n // 2):
            left = 2 * i + 1
            right = 2 * i + 2
            if left < n and arr[i] < arr[left]:
                return False
            if right < n and arr[i] < arr[right]:
                return False
        return True
    if heap_type == "min":
        for i in range(n // 2):
            left = 2 * i + 1
            right = 2 * i + 2
            if left < n and arr[i] > arr[left]:
                return False
            if right < n and arr[i] > arr[right]:
                return False
        return True
    
def identical_heaps(arr1, arr2):
    if len(arr1) != len(arr2):
        return False
    if arr1 != arr2:
        return False
    
    type1 = heap_type(arr1)
    type2 = heap_type(arr2)

    if type1 != type2:
        return False
    if not valid_heap(arr1, type1):
        return False
    if not valid_heap(arr2, type2):
        return False
    
    return True

try:
    arr1 = list(map(int, input("Enter the elements of heap 1 : ").split()))
    arr2 = list(map(int, input("Enter the elements of heap 2 : ").split()))
    print("true" if identical_heaps(arr1, arr2) else "false")
except:
    print("Invalid input. Please try with a valid input.")
