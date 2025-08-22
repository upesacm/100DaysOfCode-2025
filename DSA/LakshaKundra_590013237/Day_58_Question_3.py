def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2
    if l < n and arr[l] > arr[largest]:
        largest = l
    if r < n and arr[r] > arr[largest]:
        largest = r
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def replace_root(arr, new_element):
    arr[0] = new_element
    heapify(arr, len(arr), 0)
    return arr

print(replace_root([50, 30, 20, 15, 10, 8, 16], 25))
print(replace_root([100, 80, 70, 60, 50, 40, 30], 35))
