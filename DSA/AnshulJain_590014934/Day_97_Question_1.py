def min_palindrome_cuts(s):
    n = len(s)
    pal = [[False] * n for _ in range(n)]
    for i in range(n):
        pal[i][i] = True
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            if s[i] == s[j]:
                if length == 2 or pal[i + 1][j - 1]:
                    pal[i][j] = True
    cuts = [0] * n
    for i in range(n):
        if pal[0][i]:
            cuts[i] = 0
        else:
            cuts[i] = min(cuts[j] + 1 for j in range(i) if pal[j + 1][i])
    return cuts[-1]

s = input().strip()
print(min_palindrome_cuts(s))
