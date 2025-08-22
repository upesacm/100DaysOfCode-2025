def longest_substring_with_all_distinct_characters(s):
    char_index_map = {}
    max_length = 0
    start = 0

    for end in range(len(s)):
        if s[end] in char_index_map:
            start = max(start, char_index_map[s[end]] + 1)

        char_index_map[s[end]] = end
        max_length = max(max_length, end - start + 1)

    return max_length
