# Implement queue traversal with conditional counting to classify and enumerate even and odd elements while maintaining queue integrity and computational accuracy.
input_str = input("Enter the numbers separated by space: ")

queue = list(map(int, input_str.split()))

even_count = 0
odd_count = 0

for num in queue:
    if num % 2 == 0:
        even_count += 1
    else:
        odd_count += 1

print("Even:", even_count, "Odd:", odd_count)
