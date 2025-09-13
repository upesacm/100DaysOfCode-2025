from collections import deque

def check(a, b):
    diff = 0
    for i in range(len(a)):
        if a[i] != b[i]:
            diff += 1
            if diff > 1:
                return False
    return diff == 1

def ladder(begin, end, words):
    s = set(words)
    if end not in s:
        return 0
    q = deque([(begin, 1)])
    while q:
        w, d = q.popleft()
        if w == end:
            return d
        for nxt in list(s):
            if check(w, nxt):
                q.append((nxt, d + 1))
                s.remove(nxt)
    return 0

begin = input().strip()
end = input().strip()
n = int(input())
words = [input().strip() for _ in range(n)]
print(ladder(begin, end, words))
    