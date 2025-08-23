from collections import Counter

def can_form_palindrome(s):
	freq = Counter(s)
	odd_count = sum(1 for count in freq.values() if count % 2 == 1)
	return "Yes" if odd_count <= 1 else "No"

# Example usage:
if __name__ == "__main__":
	print(can_form_palindrome("civic"))  # Output: Yes
	print(can_form_palindrome("aabbcc"))  # Output: Yes
	print(can_form_palindrome("abc"))  # Output: No
