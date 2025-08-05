def longest_substring_k_unique_characters(string, k):
    if k == 0:
        return 0
    
    start = 0
    max_len = 0
    frequency = {}

    for end in range(len(string)):
        # Add current character to the frequency map
        frequency[string[end]] = frequency.get(string[end], 0) + 1

        # Shrink the window until we have at most k unique characters
        while len(frequency) > k:
            frequency[string[start]] -= 1
            if frequency[string[start]] == 0:
                del frequency[string[start]]
            start += 1

        # Check if the current windowhas exactly k unique characters
        if len(frequency) == k:
            max_len = max(max_len, end - start + 1)

    return max_len

try:
    string = input("Enter a string : ")
    k = int(input("Enter the value of k : "))
    print(longest_substring_k_unique_characters(string, k))
except:
    print("Invalid input. Please try with a valid input.")
