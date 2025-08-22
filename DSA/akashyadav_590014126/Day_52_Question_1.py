def has_pair_sum(arr,x):
    arr.sort()
    left,right=0,len(arr)-1

    while left < right:
        current_sum = arr[left] +arr[right]
        if current_sum == x:
            return True
        elif current_sum < x:
            left += 1
        else:
            right -= 1

    return False

#example
print(has_pair_sum([1,2,3,4,5,6,7],9))