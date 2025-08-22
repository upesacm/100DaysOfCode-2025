def totalFruit(fruits):
    from collections import defaultdict
    fruit_count = defaultdict(int)
    left = max_len = 0
    for right in range(len(fruits)):
        fruit_count[fruits[right]] += 1
        while len(fruit_count) > 2:
            fruit_count[fruits[left]] -= 1
            if fruit_count[fruits[left]] == 0:
                del fruit_count[fruits[left]]
            left += 1
        max_len = max(max_len, right - left + 1)
    
    return max_len

print(totalFruit([1, 2, 1]))         
print(totalFruit([0, 1, 2, 2]))