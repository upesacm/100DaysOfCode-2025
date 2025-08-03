class Solution:
    def isolateBit(self, n):
        i=0
        while n:
            if (n&1<<i) !=0:
                return 1<<i
            else:
                i+=1
def main():
    n = int(input("Enter the number: "))
    sol = Solution()
    result = sol.isolateBit(n)
    print(result)  
if __name__ == "__main__":
    main()