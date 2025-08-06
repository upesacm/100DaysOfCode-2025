def min_window_substring(s, t):
    if not s or not t or len(t) > len(s):
        return ""
    
    # Step 1 : Build frequency map for t
    freq_t = {}
    for char in t:
        freq_t[char] = freq_t.get(char, 0) + 1

    required = len(freq_t)
    window_counts = {}
    formed = 0

    l = 0
    min_len = len(s) + 1
    min_window = ""

    for r in range(len(s)):
        char = s[r]
        window_counts[char] = window_counts.get(char, 0) + 1

        if char in freq_t and window_counts[char] == freq_t[char]:
            formed += 1

        # Try to shrink the window
        while l <= r and formed == required:
            if (r - l + 1) < min_len:
                min_len = r - l + 1
                min_window = s[l:r+1]

            window_counts[s[l]] -= 1
            if s[l] in freq_t and window_counts[s[l]] < freq_t[s[l]]:
                formed -= 1
            l += 1

    return min_window

try:
    string = input("Enter a string : ")
    t = input("Enter the value of t : ")
    print(f"\"{min_window_substring(string, t)}\"")
except:
    print("Invalid input. Please try with a valid input.")
