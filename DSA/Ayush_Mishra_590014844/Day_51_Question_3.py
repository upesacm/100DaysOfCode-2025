def min_window_substring(s, t):
    if not s or not t:
        return ""

    freq_t = {}
    for ch in t:
        freq_t[ch] = freq_t.get(ch, 0) + 1

    freq_s = {}
    have, need = 0, len(freq_t)
    left = 0
    res = [-1, -1]
    res_len = float('inf')

    for right in range(len(s)):
        ch = s[right]
        freq_s[ch] = freq_s.get(ch, 0) + 1

        if ch in freq_t and freq_s[ch] == freq_t[ch]:
            have += 1

        while have == need:
            if right - left + 1 < res_len:
                res = [left, right]
                res_len = right - left + 1

            freq_s[s[left]] -= 1
            if s[left] in freq_t and freq_s[s[left]] < freq_t[s[left]]:
                have -= 1
            left += 1

    return s[res[0]:res[1]+1] if res_len != float('inf') else ""

s = input().strip()
t = input().strip()
print(min_window_substring(s, t))
