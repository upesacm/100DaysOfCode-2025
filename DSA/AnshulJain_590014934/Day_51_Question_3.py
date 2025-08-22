from collections import Counter
s = input("Enter string s: ")#taking input from the user 
t = input("Enter string t: ")#taking input from the user 
if not s or not t:
    print("")
else:
    target_count = Counter(t)
    window_count = {}
    have = 0
    need = len(target_count)
    res = [-1, -1]
    res_len = float("inf")
    left = 0
    for right in range(len(s)):
        char = s[right]
        window_count[char] = window_count.get(char, 0) + 1
        if char in target_count and window_count[char] == target_count[char]:
            have += 1
        while have == need:
            if (right - left + 1) < res_len:
                res = [left, right]
                res_len = right - left + 1
            window_count[s[left]] -= 1
            if s[left] in target_count and window_count[s[left]] < target_count[s[left]]:
                have -= 1
            left += 1
    l, r = res
    print(s[l:r+1] if res_len != float("inf") else "")
#for eample:
# Input: s = "ADOBECODEBANC", t = "ABC"
# Output: "BANC"
