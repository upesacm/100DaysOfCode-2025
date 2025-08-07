def total_fruit(fruits):
    from collections import defaultdict
    count = defaultdict(int)
    left = 0
    max_len = 0
    for right in range(len(fruits)):
        count[fruits[right]] += 1
        while len(count) > 2:
            count[fruits[left]] -= 1
            if count[fruits[left]] == 0:
                del count[fruits[left]]
            left += 1
        max_len = max(max_len, right - left + 1)
    return max_len

print(total_fruit([1,2,1]))      # 3
print(total_fruit([0,1,2,2]))    # 3
