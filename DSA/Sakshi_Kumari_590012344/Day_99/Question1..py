def array_string_analysis(arr, text):
    sum_positive = 0
    for num in arr:
        if num > 0:
            sum_positive += num

    vowel_count = 0
    text = text.lower()
    for ch in text:
        if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u':
            vowel_count += 1

    return sum_positive, vowel_count


n = int(input("Enter number of elements in array: "))
arr = []
for i in range(n):
    value = int(input("Enter element: "))
    arr.append(value)

text = input("Enter a string: ")

sum_result, vowel_result = array_string_analysis(arr, text)

print("Sum of positive numbers =", sum_result)
print("Number of vowels =", vowel_result)

