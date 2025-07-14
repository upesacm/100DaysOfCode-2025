class Solution:
    def SetithBit(self, n, i):
        n = n|(1<<i)
        return n
            
def main():
    n = int(input("Enter the number: "))
    i = int(input("Enter i: "))
    sol = Solution()
    result = sol.SetithBit(n, i)
    print(result)  
if __name__ == "__main__":
    main()