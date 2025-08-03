class Solution:
    def powerOfTwo(self, n):
        if n&(n-1) == 0:
            return "Yes"
        else:
            return "No"
def main():
    n = int(input("Enter the number: "))
    sol = Solution()
    result = sol.powerOfTwo(n)
    print(result)  
if __name__ == "__main__":
    main()