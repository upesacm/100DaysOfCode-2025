def can_form_palindrome(s):
    counts = {}
    for ch in s:
        counts[ch] = counts.get(ch, 0) + 1
    odd = 0
    for v in counts.values():
        if v % 2 != 0:
            odd += 1
            if odd > 1:
                return False
    return True
