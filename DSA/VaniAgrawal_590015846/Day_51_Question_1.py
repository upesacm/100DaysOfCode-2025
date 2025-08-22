#Implement dynamic sliding window with character frequency tracking to find the longest substring maintaining exactly k unique characters.
s = input("Enter the string: ")
k = int(input("Enter k: "))

n = len(s)
max_len = 0
start = 0
char_count = {}

for end in range(n):
    char = s[end]
    char_count[char] = char_count.get(char, 0) + 1

    while len(char_count) > k:
        start_char = s[start]
        char_count[start_char] -= 1
        if char_count[start_char] == 0:
            del char_count[start_char]
        start += 1

    if len(char_count) == k:
        max_len = max(max_len, end - start + 1)

print("Output:")
print(max_len)
