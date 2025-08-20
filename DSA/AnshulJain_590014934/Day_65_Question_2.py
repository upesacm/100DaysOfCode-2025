n = int(input("Enter number of pairs: "))
pairs = []
for _ in range(n):
    a, b = map(int, input().split())
    pairs.append((a, b))
pairs.sort(key=lambda x: x[1])
count = 0
end = float('-inf')
for a, b in pairs:
    if a > end:
        count += 1
        end = b
print(count)
