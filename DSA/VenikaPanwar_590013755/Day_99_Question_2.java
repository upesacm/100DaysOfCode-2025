public class Day_99_Question_2 {

    // Returns an int array: [sum of negatives, consonant count]
    public static int[] arraySumAndConsonantCount(int[] arr, String str) {
        int sum = 0;
        for (int num : arr) {
            if (num < 0) sum += num;
        }
        int consonants = 0;
        String s = str.toLowerCase();
        for (char c : s.toCharArray()) {
            if ("bcdfghjklmnpqrstvwxyz".indexOf(c) != -1) consonants++;
        }
        return new int[]{sum, consonants};
    }

    public static void main(String[] args) {
        int[] arr1 = {1, -2, 3, -4, 5};
        String str1 = "Hello World";
        int[] res1 = arraySumAndConsonantCount(arr1, str1);
        System.out.println("Sum: " + res1[0] + ", Consonants: " + res1[1]); // Output: Sum: -6, Consonants: 7

        int[] arr2 = {-1, -2, -3};
        String str2 = "Programming";
        int[] res2 = arraySumAndConsonantCount(arr2, str2);
        System.out.println("Sum: " + res2[0] + ", Consonants: " + res2[1]); // Output: Sum: -6, Consonants: 7
    }
}
