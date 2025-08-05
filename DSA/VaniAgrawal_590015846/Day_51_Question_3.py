# Implement advanced sliding window with dual frequency tracking to find minimal substrings containing all required characters efficiently.
s = input("Enter string s: ")
t = input("Enter string t: ")

from collections import Counter

if not s or not t:
    print("Output:")
    print("")
else:
    dict_t = Counter(t)
    required = len(dict_t)

    l, r = 0, 0
    formed = 0
    window_counts = {}

    ans = (float("inf"), None, None)

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
        print("Output:")
        print("")
    else:
        print("Output:")
        print(s[ans[1]: ans[2]+1])
