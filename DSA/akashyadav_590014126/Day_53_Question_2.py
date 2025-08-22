def totalFruit(fruits):
    from collections import defaultdict

    fruitCount = defaultdict(int)
    left = 0
    maxLength = 0

    for right in range(len(fruits)):
        fruitCount[fruits[right]] += 1

        while len(fruitCount) > 2:
            fruitCount[fruits[left]] -= 1
            if fruitCount[fruits[left]] == 0:
                del fruitCount[fruits[left]]
            left += 1

        maxLength = max(maxLength, right - left + 1)

    return maxLength
