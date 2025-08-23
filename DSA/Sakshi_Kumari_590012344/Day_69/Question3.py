def length_of_longest_substring(s):
    seen = set()
    left = 0
    longest = 0
    for right in range(len(s)):
        while s[right] in seen:
            seen.remove(s[left])
            left += 1
        seen.add(s[right])
        longest = max(longest, right - left + 1)
    return longest
