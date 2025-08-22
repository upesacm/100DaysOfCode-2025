from collections import Counter, defaultdict

def min_window(s, t):
    if not s or not t:
        return ""

    target_count = Counter(t)     
    window_count = defaultdict(int)

    have, need = 0, len(target_count) 
    res = [0, float('inf')]           
    left = 0

    for right in range(len(s)):
        char = s[right]
        window_count[char] += 1

        if char in target_count and window_count[char] == target_count[char]:
            have += 1

        while have == need: 

            if (right - left + 1) < (res[1] - res[0]):
                res = [left, right + 1]

            window_count[s[left]] -= 1
            if s[left] in target_count and window_count[s[left]] < target_count[s[left]]:
                have -= 1
            left += 1

    l, r = res
    return s[l:r] if res[1] < float('inf') else ""
