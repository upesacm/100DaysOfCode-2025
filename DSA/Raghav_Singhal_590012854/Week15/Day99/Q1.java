class Q1 {
    public static void main(String[] args) {
        int[] arr = {1, -2, 3, -4, 5};
        String str = "Hello World";

        int sum = 0;
        for (int num : arr) {
            if (num > 0) sum += num;
        }

        int vowelCount = 0;
        str = str.toLowerCase();
        for (char c : str.toCharArray()) {
            if ("aeiou".indexOf(c) != -1) vowelCount++;
        }

        System.out.println("Sum: " + sum + ", Vowels: " + vowelCount);
    }
}
