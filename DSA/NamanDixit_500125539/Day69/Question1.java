import java.util.*;

public class Question1 {

    // Function to check palindrome rearrangement feasibility
    public static String canFormPalindrome(String str) {
        int[] freq = new int[256]; // ASCII size

        // Count frequency of characters
        for (char ch : str.toCharArray()) {
            freq[ch]++;
        }

        int oddCount = 0;
        for (int count : freq) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }

        // If length is even, no odd count allowed
        // If length is odd, only one odd count allowed
        if ((str.length() % 2 == 0 && oddCount == 0) ||
            (str.length() % 2 == 1 && oddCount == 1)) {
            return "Yes";
        } else {
            return "No";
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        System.out.println(canFormPalindrome(input));
    }
}
