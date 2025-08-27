def split_array_into_equal_sum(array):
    total = sum(array)
    if total % 2 != 0:
        return False
    
    target = total // 2
    possible_sums = {0}

    for num in array:
        new_sums = set()
        for s in possible_sums:
            if s + num == target:
                return True
            if s + num < target:
                new_sums.add(s + num)
        possible_sums.update(new_sums)

    return target in possible_sums

try:
    array = list(map(int, input("Enter the elements of the arr separated by spaces : ").split()))
    print("true" if split_array_into_equal_sum(array) else "false")
except:
    print("Invalid input. Please try with a valid input.")
