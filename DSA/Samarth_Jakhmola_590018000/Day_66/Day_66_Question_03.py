def distribute_candies(ratings):
    n = len(ratings)
    if n == 0:
        return 0, []
    
    candies = [1] * n   # Everyone gets at least 1

    # Left -> Right : Fix with respect to left neighbour
    for i in range(1, n):
        if ratings[i] > ratings[i - 1]:
            candies[i] = candies[i - 1] + 1

    # Right -> Left : Fix with respect to right neighbour
    for i in range(n - 2, -1, -1 ):
        if ratings[i] > ratings[i + 1]:
            candies[i] = max(candies[i], candies[i + 1] + 1)

    return sum(candies)

try:
    ratings = list(map(int, input("Enter the different ratings of candies given by children, separated by spaces : ").split()))
    print(distribute_candies(ratings))
except:
    print("Invalid input. Please try with a valid input.")
