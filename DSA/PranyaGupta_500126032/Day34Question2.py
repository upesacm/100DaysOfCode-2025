class Solution:
    def subOne(self, n):
        i=0
        while n:
            if (n&1<<i) == 0:
                n^= (1<<i)
                i+=1
            else:
                n^=(1<<i)
                return n    

def main():
    n = int(input("Enter the number: "))
    sol = Solution()
    result = sol.subOne(n)
    print(result)  
if __name__ == "__main__":
    main()