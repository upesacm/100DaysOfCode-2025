class Solution:
    def unsetBit(self, n):
        i=0
        while n:
            if (n&1<<i) !=0:
                n=n^((1<<i))
                return n
            else:
                i+=1
def main():
    n = int(input("Enter the number: "))
    sol = Solution()
    result = sol.unsetBit(n)
    print(result)  
if __name__ == "__main__":
    main()