def total_fruit(fruits):
    fruit_count = {}
    left = 0
    max_len = 0

    for right in range(len(fruits)):
        fruit = fruits[right]
        if fruit in fruit_count:
            fruit_count[fruit] += 1
        else:
            fruit_count[fruit] = 1

        while len(fruit_count) > 2:
            left_fruit = fruits[left]
            fruit_count[left_fruit] -= 1
            if fruit_count[left_fruit] == 0:
                del fruit_count[left_fruit]
            left += 1

        current_window_size = right - left + 1
        if current_window_size > max_len:
            max_len = current_window_size

    return max_len

#Fixed Input
print(total_fruit([1, 2, 1]))
