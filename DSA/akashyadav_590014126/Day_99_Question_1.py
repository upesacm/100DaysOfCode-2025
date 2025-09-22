def array_sum_and_vowel_count(arr, s):
    sum_positive = sum(x for x in arr if x > 0)
    vowels = set('aeiouAEIOU')
    vowel_count = sum(1 for ch in s if ch in vowels)
    return sum_positive, vowel_count

# Example 1
arr1 = [1, -2, 3, -4, 5]
string1 = "Hello World"
print("Sum:", array_sum_and_vowel_count(arr1, string1)[0], "Vowels:", array_sum_and_vowel_count(arr1, string1)[1])

# Example 2
arr2 = [-1, -2, -3]
string2 = "Programming"
print("Sum:", array_sum_and_vowel_count(arr2, string2)[0], "Vowels:", array_sum_and_vowel_count(arr2, string2)[1])
