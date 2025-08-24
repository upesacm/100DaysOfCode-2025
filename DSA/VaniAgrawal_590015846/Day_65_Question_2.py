# Implement greedy pair chaining using end-value sorting to maximize compatible pair sequences with optimal dependency satisfaction.

pairs = []
n = int(input("Enter number of pairs: "))
for _ in range(n):
    a, b = map(int, input("Enter pair (a b): ").split())
    pairs.append((a, b))

pairs.sort(key=lambda x: x[1])
count = 0
end = float('-inf')

for pair in pairs:
    if pair[0] > end:
        count += 1
        end = pair[1]

print(count)
