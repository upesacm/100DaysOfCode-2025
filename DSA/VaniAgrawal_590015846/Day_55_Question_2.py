# Implement sliding window with hash-based character tracking to find maximum length substrings maintaining complete character uniqueness.
s = input("Enter the string: ")

char_set = set()
left = 0
max_len = 0

for right in range(len(s)):
    while s[right] in char_set:
        char_set.remove(s[left])
        left += 1
    char_set.add(s[right])
    max_len = max(max_len, right - left + 1)

print("Length of longest substring:", max_len)
