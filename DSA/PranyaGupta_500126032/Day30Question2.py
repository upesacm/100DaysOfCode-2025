class Solution:
    def toggleithbit(self, n, i):
        return n^(1<<i)
def main():
    n = int(input("Enter the number: "))
    i = int(input("Enter i: "))
    sol = Solution()
    result = sol.toggleithbit(n, i)
    print(result)  
if __name__ == "__main__":
    main()