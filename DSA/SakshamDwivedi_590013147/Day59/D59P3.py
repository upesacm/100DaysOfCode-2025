def is_heap(arr, heap_type="max"):
    n = len(arr)
    for i in range(n // 2):
        l, r = 2*i+1, 2*i+2
        if l < n:
            if heap_type == "max" and arr[i] < arr[l]: return False
            if heap_type == "min" and arr[i] > arr[l]: return False
        if r < n:
            if heap_type == "max" and arr[i] < arr[r]: return False
            if heap_type == "min" and arr[i] > arr[r]: return False
    return True

def heaps_identical(a1, a2, heap_type="max"):
    return a1 == a2 and is_heap(a1, heap_type) and is_heap(a2, heap_type)


#Fixed Input
arr1 = [10, 9, 8]
arr2 = [10, 9, 8]
print(heaps_identical(arr1, arr2))
print(heaps_identical(arr1, arr2, "min"))

arr3 = [1, 3, 2]
arr4 = [1, 3, 2]
print(heaps_identical(arr3, arr4, "min"))
