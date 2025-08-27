n = int(input("Enter number of children: "))#taking input from the user 
ratings = list(map(int, input("Enter ratings: ").split()))#taking input from the user
candies = [1] * n
for i in range(1, n):
    if ratings[i] > ratings[i - 1]:
        candies[i] = candies[i - 1] + 1
for i in range(n - 2, -1, -1):
    if ratings[i] > ratings[i + 1]:
        candies[i] = max(candies[i], candies[i + 1] + 1)
print(sum(candies))
#for example:
# Input:
# Enter number of children: 3
# Enter ratings: 1 2 2
# Output:4