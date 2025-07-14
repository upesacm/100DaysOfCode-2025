class Solution:
    def EvenOrOdd(self, n):
        return n & 1 == 0     
def main():
    n = int(input("Enter the number: "))
    
    sol = Solution()
    result = sol.EvenOrOdd(n)
    if(result):
        print("Even")
    else:
        print("Odd")    
if __name__ == "__main__":
    main()