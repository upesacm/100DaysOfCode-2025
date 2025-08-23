def can_form_palindrome(s: str) -> str:
    from collections import Counter

    freq = Counter(s)
    odd_count = sum(1 for count in freq.values() if count % 2 != 0)

    return "Yes" if odd_count <= 1 else "No"
