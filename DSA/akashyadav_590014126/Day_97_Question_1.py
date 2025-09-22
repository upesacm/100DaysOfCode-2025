def minCut(s: str) -> int:
    n = len(s)
    is_palindrome = [[False]*n for _ in range(n)]
    for end in range(n):
        for start in range(end + 1):
            if s[start] == s[end] and (end - start <= 2 or is_palindrome[start+1][end-1]):
                is_palindrome[start][end] = True
    cuts = [0]*n
    for i in range(n):
        if is_palindrome[0][i]:
            cuts[i] = 0
        else:
            cuts[i] = float('inf')
            for j in range(i):
                if is_palindrome[j+1][i]:
                    cuts[i] = min(cuts[i], cuts[j] + 1)
    return cuts[-1]

print("Input:")
s = "aab"
print("String:", s)
print("Output:")
print(minCut(s))

print("\nInput:")
s = "a"
print("String:", s)
print("Output:")
print(minCut(s))
