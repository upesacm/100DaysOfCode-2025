def rearrange_to_form_palindrome(string):
    frequency = {}

    for char in string:
        frequency[char] = frequency.get(char, 0) + 1   # Counting the frequencies of each element in the string.

    odd_count = 0  # To store the count of elements with odd frequencies.
    for count in frequency.values():
        if count % 2 != 0:
            odd_count += 1

    return "Yes" if odd_count <= 1 else "No"

try:
    string = input("Enter a string : ")
    print(rearrange_to_form_palindrome(string))
except:
    print("Invalid input. Please try with a valid input.")
