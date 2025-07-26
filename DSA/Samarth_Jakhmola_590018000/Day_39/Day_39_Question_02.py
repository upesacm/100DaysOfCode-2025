def  span(prices):
    span = [0] * len(prices)
    stack = []

    for i in range(len(prices)):
        while stack and prices[i] >= prices[stack[-1]]:
            stack.pop()

        if not stack:
            span[i] = i + 1
        else:
            span[i] = i - stack[-1]

        stack.append(i)
    return span

try:
    if __name__ == "__main__":
        prices = list(map(int, input("Enter the stock prices separated by spaces : ").split()))
        print(span(prices))
except:
     print("Invalid input. Please try with a valid input.")
