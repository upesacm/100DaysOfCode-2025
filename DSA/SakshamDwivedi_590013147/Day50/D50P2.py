def count_anagram_occurrences(text, pattern):
    def idx(c):
        return ord(c) - ord('a')

    n, k = len(text), len(pattern)
    if n < k: return 0

    pf = [0] * 26
    wf = [0] * 26

    for i in range(k):
        pf[idx(pattern[i])] += 1
        wf[idx(text[i])] += 1

    count = 1 if pf == wf else 0

    for i in range(k, n):
        wf[idx(text[i])] += 1
        wf[idx(text[i - k])] -= 1
        if wf == pf: count += 1

    return count

#Fixed Input
print(count_anagram_occurrences("forxxorfxdofr", "for"))
