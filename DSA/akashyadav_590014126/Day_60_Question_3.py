import heapq
from collections import Counter

def top_k_frequent_element(arr,k):
    freq_map=Counter(arr)

    top_k=heapq.n.largest(k,freq_map.items(),key=lambda x:+1)

    return [item[0] for item in top_k]