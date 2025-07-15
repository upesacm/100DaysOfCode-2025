class Solution:
    def NoOfsetbit(self, n):
        count = 0
        while(n>0):
            if n&1!=0:
                count+=1
            n=n>>1
        return count        

def main():
    n = int(input("Enter the number: "))
    sol = Solution()
    result = sol.NoOfsetbit(n)
    print(result)  
if __name__ == "__main__":
    main()