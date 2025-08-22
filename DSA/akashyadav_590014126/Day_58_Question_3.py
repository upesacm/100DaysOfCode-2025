def heapify(arr,n,i):
    largest=i
    left=2*i+1
    right=2*i+2
    if left<n and arr[left]>arr[largest]:
        largest=left
    if right<n and arr[right]>arr[largest]:
        largest=right
    
    if largest != i:
        arr[i],arr[largest]=arr[largest],arr[i]
        heapify(arr,n,largest)

def replace_root(arr,new_element):
    arr[0]=new_element
    heapify(arr,len(arr),0)
    return arr