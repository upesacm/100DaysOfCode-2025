public class Day_99_Question_1 {

    // Returns an int array: [sum of positives, vowel count]
    public static int[] arraySumAndVowelCount(int[] arr, String str) {
        int sum = 0;
        for (int num : arr) {
            if (num > 0) sum += num;
        }
        int vowels = 0;
        String s = str.toLowerCase();
        for (char c : s.toCharArray()) {
            if ("aeiou".indexOf(c) != -1) vowels++;
        }
        return new int[]{sum, vowels};
    }

    public static void main(String[] args) {
        int[] arr1 = {1, -2, 3, -4, 5};
        String str1 = "Hello World";
        int[] res1 = arraySumAndVowelCount(arr1, str1);
        System.out.println("Sum: " + res1[0] + ", Vowels: " + res1[1]); // Output: Sum: 9, Vowels: 3

        int[] arr2 = {-1, -2, -3};
        String str2 = "Programming";
        int[] res2 = arraySumAndVowelCount(arr2, str2);
        System.out.println("Sum: " + res2[0] + ", Vowels: " + res2[1]); // Output: Sum: 0, Vowels: 3
    }
}