class Solution:
    def swap(self, n1, n2):
        n1 = n1^n2
        n2 = n1^n2
        n1 = n1^n2
        return f"{n1} {n2}"
def main():
    n1 = int(input("Enter the number1: "))
    n2 = int(input("Enter the number2: "))

    sol = Solution()
    result = sol.swap(n1, n2)
    print(result)  
if __name__ == "__main__":
    main()