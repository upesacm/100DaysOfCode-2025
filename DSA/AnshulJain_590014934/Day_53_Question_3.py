arr = list(map(int, input("Enter array elements separated by space: ").split()))
n = len(arr)
i = 1
longest = 0
while i < n - 1:
    if arr[i - 1] < arr[i] > arr[i + 1]:
        left = i - 1
        while left > 0 and arr[left - 1] < arr[left]:
            left -= 1
        right = i + 1
        while right < n - 1 and arr[right] > arr[right + 1]:
            right += 1
        longest = max(longest, right - left + 1)
        i = right
    else:
        i += 1
print("Length of the longest mountain:", longest)
#for example:
# Input: 2 1 1 5 6 2 3
# Output: Length of the longest mountain: 4