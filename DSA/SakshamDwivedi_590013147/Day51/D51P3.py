def min_window_substring(s, t):
    if not s or not t:
        return ""

    required = [0] * 128
    for i in t:
        required[ord(i)] += 1

    left = 0
    min_len = float('inf')
    min_start = 0
    count = len(t)

    for right in range(len(s)):
        if required[ord(s[right])] > 0:
            count -= 1
        required[ord(s[right])] -= 1

        while count == 0:
            if right - left + 1 < min_len:
                min_len = right - left + 1
                min_start = left

            required[ord(s[left])] += 1
            if required[ord(s[left])] > 0:
                count += 1
            left += 1

    if min_len != float('inf'):
      return s[min_start:min_start + min_len]
    else:
      ""
print(min_window_substring("ADOBECODEBANC", "ABC"))
