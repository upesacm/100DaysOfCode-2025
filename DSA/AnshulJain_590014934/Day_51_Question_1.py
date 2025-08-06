s = input("Enter the string: ")
k = int(input("Enter the value of k: "))
n = len(s)
left = 0
right = 0
max_len = 0
char_freq = {}
while right < n:
    char_freq[s[right]] = char_freq.get(s[right], 0) + 1
    while len(char_freq) > k:
        char_freq[s[left]] -= 1
        if char_freq[s[left]] == 0:
            del char_freq[s[left]]
        left += 1
    if len(char_freq) == k:
        max_len = max(max_len, right - left + 1)
    right += 1
print(max_len)
#for example:
# Input: "aaaa", k = 2
# Output: 0
