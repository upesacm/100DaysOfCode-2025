from collections import Counter

def min_window(s, t):
    if not s or not t:
        return ""
    
    dict_t = Counter(t)
    required = len(dict_t)
    l, r = 0, 0
    formed = 0
    window_counts = {}
    ans = float("inf"), None, None

    while r < len(s):
        character = s[r]
        window_counts[character] = window_counts.get(character, 0) + 1

        if character in dict_t and window_counts[character] == dict_t[character]:
            formed += 1

        while l <= r and formed == required:
            if r - l + 1 < ans[0]:
                ans = (r - l + 1, l, r)
            
            window_counts[s[l]] -= 1
            if s[l] in dict_t and window_counts[s[l]] < dict_t[s[l]]:
                formed -= 1
            l += 1

        r += 1

    return "" if ans[0] == float("inf") else s[ans[1]: ans[2] + 1]

print(min_window("ADOBECODEBANC", "ABC"))  # Output: "BANC"
print(min_window("a", "a"))                # Output: "a"
