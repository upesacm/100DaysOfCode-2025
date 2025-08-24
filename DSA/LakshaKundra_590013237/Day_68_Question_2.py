import heapq
from collections import Counter

def rearrange(s):
    c=Counter(s)
    h=[(-v,k) for k,v in c.items()]
    heapq.heapify(h)
    res=[]
    prev=(0,'')
    while h:
        v,k=heapq.heappop(h)
        res.append(k)
        if prev[0]<0: heapq.heappush(h,prev)
        prev=(v+1,k)
    return ''.join(res) if len(res)==len(s) else ''

print(rearrange("aab"))
print(rearrange("aaab"))
