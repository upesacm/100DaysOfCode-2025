# -------------------- Greedy Problems Module --------------------

# 1️⃣ Activity Selection Problem
def activity_selection(start, end):
    n = len(start)
    activities = [(start[i], end[i], i) for i in range(n)]
    # Sort by finish time
    activities.sort(key=lambda x: x[1])

    selected = [activities[0]]
    last_end = activities[0][1]

    for i in range(1, n):
        if activities[i][0] >= last_end:
            selected.append(activities[i])
            last_end = activities[i][1]

    print("Selected activities (start, end, index):", selected)
    return len(selected)

# 2️⃣ Fractional Knapsack
def fractional_knapsack(weights, values, capacity):
    n = len(weights)
    ratio = [(values[i]/weights[i], weights[i], values[i]) for i in range(n)]
    ratio.sort(key=lambda x: x[0], reverse=True)

    max_value = 0
    for r, w, v in ratio:
        if capacity >= w:
            max_value += v
            capacity -= w
        else:
            max_value += r * capacity
            break
    return max_value

# 3️⃣ Job Scheduling Maximum Profit
def job_scheduling(jobs):
    # Each job = (id, deadline, profit)
    jobs.sort(key=lambda x: x[2], reverse=True)  # Sort by profit descending
    n = len(jobs)
    max_deadline = max(job[1] for job in jobs)
    slot = [None] * max_deadline

    total_profit = 0
    scheduled_jobs = []

    for job in jobs:
        for j in range(job[1]-1, -1, -1):  # Latest available slot
            if slot[j] is None:
                slot[j] = job[0]
                total_profit += job[2]
                scheduled_jobs.append(job)
                break
    print("Scheduled Jobs (id, deadline, profit):", scheduled_jobs)
    return total_profit

# 4️⃣ Minimum Coins Problem (Greedy)
def min_coins_greedy(coins, amount):
    coins.sort(reverse=True)
    count = 0
    used = []
    for coin in coins:
        while amount >= coin:
            amount -= coin
            count += 1
            used.append(coin)
    if amount != 0:
        print("Exact amount not achievable with given coins.")
        return None
    print("Coins used:", used)
    return count

# 5️⃣ Stock Buy/Sell Maximum Profit
def max_profit_stocks(prices):
    min_price = prices[0]
    max_profit = 0
    for price in prices[1:]:
        max_profit = max(max_profit, price - min_price)
        min_price = min(min_price, price)
    return max_profit

# -------------------- Menu Interface --------------------
def main():
    while True:
        print("\n--- GREEDY ALGORITHMS MENU ---")
        print("1. Activity Selection")
        print("2. Fractional Knapsack")
        print("3. Job Scheduling Maximum Profit")
        print("4. Minimum Coins Problem")
        print("5. Stock Buy/Sell Maximum Profit")
        print("6. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            start = list(map(int, input("Enter start times: ").split()))
            end = list(map(int, input("Enter end times: ").split()))
            print("Maximum activities:", activity_selection(start, end))

        elif choice == 2:
            n = int(input("Number of items: "))
            values = list(map(int, input("Enter values: ").split()))
            weights = list(map(int, input("Enter weights: ").split()))
            capacity = int(input("Enter knapsack capacity: "))
            print("Maximum value:", fractional_knapsack(weights, values, capacity))

        elif choice == 3:
            n = int(input("Number of jobs: "))
            jobs = []
            print("Enter each job as: id deadline profit")
            for _ in range(n):
                job = tuple(map(int, input().split()))
                jobs.append(job)
            print("Total maximum profit:", job_scheduling(jobs))

        elif choice == 4:
            coins = list(map(int, input("Enter coin denominations: ").split()))
            amount = int(input("Enter total amount: "))
            result = min_coins_greedy(coins, amount)
            if result is not None:
                print("Minimum coins needed:", result)

        elif choice == 5:
            prices = list(map(int, input("Enter stock prices: ").split()))
            print("Maximum profit:", max_profit_stocks(prices))

        elif choice == 6:
            print("Exiting...")
            break
        else:
            print("Invalid choice! Try again.")

if __name__ == "__main__":
    main()
