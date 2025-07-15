class Solution:
    def ithbit(self, n, i):
        if n&(1<<i) == 0:
            return 0
        else:
            return 1
def main():
    n = int(input("Enter the number: "))
    i = int(input("Enter i: "))
    sol = Solution()
    result = sol.ithbit(n, i)
    print(result)  
if __name__ == "__main__":
    main()