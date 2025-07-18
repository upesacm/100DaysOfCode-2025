class Solution:
    def binaryPlaindrome(self, n):
        i=0
        l = n.bit_length()
        while i < l // 2:
            lbit = (n & (1 << i))
            rbit = (n & (1 << (l - i - 1)))  

            if (lbit and not rbit) or (not lbit and rbit):
                return "No"

            i += 1

        return "Yes" 


def main():
    n = int(input("Enter the number: "))
    sol = Solution()
    result = sol.binaryPlaindrome(n)
    print(result)  
if __name__ == "__main__":
    main()