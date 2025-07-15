class Solution:
    def clearithbit(self, n, i):
        return n^(1<<i)
def main():
    n = int(input("Enter the number: "))
    i = int(input("Enter i: "))
    sol = Solution()
    result = sol.clearithbit(n, i)
    print(result)  
if __name__ == "__main__":
    main()