def min_window_substring(s, t):
    from collections import Counter

    if not s or not t:
        return ""

    dict_t = Counter(t)
    required = len(dict_t)

    l, r = 0, 0
    formed = 0
    window_counts = {}
    ans = float("inf"), None, None  # window length, left, right

    while r < len(s):
        character = s[r]
        window_counts[character] = window_counts.get(character, 0) + 1

        if character in dict_t and window_counts[character] == dict_t[character]:
            formed += 1

        while l <= r and formed == required:
            character = s[l]

            if r - l + 1 < ans[0]:
                ans = (r - l + 1, l, r)

            window_counts[character] -= 1
            if character in dict_t and window_counts[character] < dict_t[character]:
                formed -= 1
            l += 1
        r += 1

    if ans[0] == float("inf"):
        return ""
    else:
        return s[ans[1]:ans[2]+1]

# Example usage:
print(min_window_substring("ADOBECODEBANC", "ABC"))  # Output: "BANC"
print(min_window_substring("a", "a"))                # Output: "a"
