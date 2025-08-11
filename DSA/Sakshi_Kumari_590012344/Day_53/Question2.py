def total_fruit(fruits):
    fruit_count = {}
    left = 0
    max_length = 0

    for right in range(len(fruits)):
        fruit = fruits[right]
        fruit_count[fruit] = fruit_count.get(fruit, 0) + 1

        while len(fruit_count) > 2:
            left_fruit = fruits[left]
            fruit_count[left_fruit] -= 1
            if fruit_count[left_fruit] == 0:
                del fruit_count[left_fruit]
            left += 1

        max_length = max(max_length, right - left + 1)

    return max_length
