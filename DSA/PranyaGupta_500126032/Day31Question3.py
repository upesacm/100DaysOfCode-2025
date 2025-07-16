class Solution:
    def dividebyTwo(self, n):
        return n>>1;
def main():
    n = int(input("Enter the number: "))
    sol = Solution()
    result = sol.dividebyTwo(n)
    print(result)  
if __name__ == "__main__":
    main()