def max_con(arr):
    current_max = 0
    current_counting = 0

    for i in arr:
        if i == 1:
            current_counting += 1
            current_max = max(current_max, current_counting)
        else:
            current_counting = 0

    return current_max

#Fixed Input
print(max_con([1, 1, 0, 1, 1, 1]))
