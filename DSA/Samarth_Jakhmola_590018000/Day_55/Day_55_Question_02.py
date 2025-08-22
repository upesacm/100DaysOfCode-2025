def longest_substring(s):
    char_set = set()
    left = 0
    max_length = 0

    for right in range(len(s)):
        #Shrink window until no duplicate remains
        while s[right] in char_set:
            char_set.remove(s[left])
            left += 1

        # Add current char to the set
        char_set.add(s[right])

        # Update max length 
        max_length = max(max_length, right - left + 1)
    
    return max_length
    
try:
    s = input("Enter a string : ")
    print(longest_substring(s))
except:
    print("Invalid input. Please try with a valid input.")
