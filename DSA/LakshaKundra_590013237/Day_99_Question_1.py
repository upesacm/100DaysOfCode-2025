def array_string_analysis(arr, string):
    s = sum(x for x in arr if x > 0)
    v = sum(1 for ch in string.lower() if ch in "aeiou")
    return s, v

print(array_string_analysis([1, -2, 3, -4, 5], "Hello World"))
print(array_string_analysis([-1, -2, -3], "Programming"))
