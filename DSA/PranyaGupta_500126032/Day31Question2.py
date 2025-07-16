class Solution:
    def Multiplybytwo(self, n):
        return n<<1;
def main():
    n = int(input("Enter the number: "))
    sol = Solution()
    result = sol.Multiplybytwo(n)
    print(result)  
if __name__ == "__main__":
    main()