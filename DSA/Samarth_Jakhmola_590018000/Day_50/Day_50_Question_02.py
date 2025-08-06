from collections import Counter

def count_occurences(text, pattern):
    k = len(pattern)
    pattern_freq = Counter(pattern)
    window_freq = Counter()

    count = 0
    for i in range(len(text)):
        # Add current character to window
        window_freq[text[i]] += 1

        # Remove character that is left out of window
        if i >= k:
            if window_freq[text[i - k]] == 1:
                del window_freq[text[i - k]]
            else:
                window_freq[text[i - k]] -= 1

        # Compare frequency maps
        if window_freq == pattern_freq:
            count += 1

    return count

try:
    text = input("Enter the text : ")
    pattern = input("Enter the pattern : ")
    print(count_occurences(text, pattern))
except:
    print("Invalid input. Please try with a valid input.")
