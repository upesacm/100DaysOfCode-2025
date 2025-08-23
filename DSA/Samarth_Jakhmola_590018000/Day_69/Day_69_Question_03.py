def longest_substring_without_repeating(string):
    char_set = set()
    left = 0
    max_len = 0

    for right in range(len(string)):
        while string[right] in char_set:
            char_set.remove(string[left])
            left += 1
        char_set.add(string[right])
        max_len = max(max_len, right - left + 1)

    return max_len

try:
    string = input("Enter a string : ")
    print(longest_substring_without_repeating(string))
except:
    print("Invalid input. Please try with a valid input.")
