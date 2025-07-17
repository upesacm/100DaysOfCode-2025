class Solution:
    def allxor(self, arr):
        res = 0
        for n in arr:
            res ^=n
        return res    
def main():
    user_input = input("Enter elements of the array (with space in between): ")
    arr = list(map(int, user_input.strip().split()))
    sol = Solution()
    result = sol.allxor(arr)
    print(result)
if __name__ == "__main__":
    main()