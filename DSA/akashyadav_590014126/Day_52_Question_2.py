def find_pair_sum(arr,k):
    seen=set(arr)
    result=[]

    for num in arr:
        if num+k in seen:
            result.append((num,num+k))
        if num-k in seen:
            result.append((num,num-k))
    return result

#example
print(find_pair_sum([1,2,3,4,5,6],2))