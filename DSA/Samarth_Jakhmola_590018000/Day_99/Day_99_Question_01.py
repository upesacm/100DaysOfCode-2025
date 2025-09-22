def array_positive_sum_vowel_count(array, string):
    # Sum of positive numbers
    sum_positive = sum(num for num in array if num > 0)

    # Vowels count
    vowels = "aeiou"
    vowels_count = sum(1 for ch in string.lower() if ch in vowels)

    return sum_positive, vowels_count

array = list(map(int, input("Enter the elements of the array separated by spaces : ").split()))
string = input("Enter the string : ")
sum_postive, vowels_count = array_positive_sum_vowel_count(array, string)
print(f"Sum : {sum_postive}, Vowels : {vowels_count}")
