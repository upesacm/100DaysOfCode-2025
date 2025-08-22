def min_window_substring(s, t):
    from collections import Counter
    if not t or not s:
        return ""
    t_freq = Counter(t)
    window = {}
    left = 0
    min_len = float('inf')
    res = ""
    have, need = 0, len(t_freq)
    for right, char in enumerate(s):
        window[char] = window.get(char, 0) + 1
        if char in t_freq and window[char] == t_freq[char]:
            have += 1
        while have == need:
            if right - left + 1 < min_len:
                min_len = right - left + 1
                res = s[left:right+1]
            window[s[left]] -= 1
            if s[left] in t_freq and window[s[left]] < t_freq[s[left]]:
                have -= 1
            left += 1
    return res

s = "ADOBECODEBANC"
t = "ABC"
result = min_window_substring(s, t)
print(result) 