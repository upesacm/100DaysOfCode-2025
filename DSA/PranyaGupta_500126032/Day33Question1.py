class Solution:
    def haveOppositeSign(self, n1, n2):
        return (n1^n2)<0
def main():
    n1 = int(input("Enter the number1: "))
    n2 = int(input("Enter the number2: "))

    sol = Solution()
    result = sol.haveOppositeSign(n1, n2)
    print(result)  
if __name__ == "__main__":
    main()