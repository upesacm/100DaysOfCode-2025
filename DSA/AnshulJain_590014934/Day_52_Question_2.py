arr = list(map(int, input("Enetr the array:- ").split()))
k = int(input("Enter the difference k: "))
s = set(arr)
pairs = []
for num in arr:
    if num + k in s:
        pairs.append((num, num + k))
    if num - k in s:
        pairs.append((num, num - k))
print(pairs)
#for example:
#input : arr = [1, 5, 3, 4, 2], k = 2
#output : [(1, 3), (3, 5), (2, 4)]