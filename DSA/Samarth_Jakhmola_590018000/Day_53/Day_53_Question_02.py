def fruit_into_baskets(fruits):
    from collections import defaultdict

    fruit_count = defaultdict(int)  # Creates a dictionary where all the missing keys are set to 0 by default
    start = 0
    max_len = 0

    for end in range(len(fruits)):
        fruit_count[fruits[end]] += 1  # Adding current fruit to the basket

        # If more than 2 types of fruits, we shrink the window from left
        while(len(fruit_count)) > 2:
            fruit_count[fruits[start]] -= 1
            if fruit_count[fruits[start]] == 0:
                del fruit_count[fruits[start]]
            start += 1

        # Update the maximum length
        max_len = max(max_len, end - start + 1)

    return max_len

try:
    fruits = list(map(int, input("Enter the elements of the array : ").split()))
    print(fruit_into_baskets(fruits))
except:
    print("Invalid input. Please try with a valid input.")
