import java.util.*;

public class Day_68_Question_1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        
        String[] numbers = new String[n];
        System.out.println("Enter the numbers:");
        
        for (int i = 0; i < n; i++) {
            numbers[i] = scanner.next();
        }
        
        String largestNumber = createLargestNumber(numbers);
        System.out.println("Largest possible number: " + largestNumber);
        
        // Demonstrate with examples
        demonstrateExamples();
        
        scanner.close();
    }
    
    /**
     * Creates the largest possible number by arranging array elements
     * using custom concatenation-based comparison strategy
     */
    public static String createLargestNumber(String[] nums) {
        // Handle null or empty input
        if (nums == null || nums.length == 0) {
            return "0";
        }
        
        // Custom comparator that compares concatenated results
        Arrays.sort(nums, new Comparator<String>() {
            @Override
            public int compare(String firstNum, String secondNum) {
                // Compare xy vs yx to determine optimal ordering
                String concatenation1 = firstNum + secondNum;
                String concatenation2 = secondNum + firstNum;
                
                // Use descending order for maximum value
                return concatenation2.compareTo(concatenation1);
            }
        });
        
        // Handle edge case where all numbers are zeros
        if (nums[0].equals("0")) {
            return "0";
        }
        
        // Build the final result using StringBuilder for efficiency
        StringBuilder resultBuilder = new StringBuilder();
        for (String number : nums) {
            resultBuilder.append(number);
        }
        
        return resultBuilder.toString();
    }
    
    /**
     * Alternative implementation using lambda expression for modern Java approach
     */
    public static String createLargestNumberLambda(String[] nums) {
        if (nums == null || nums.length == 0) return "0";
        
        // Lambda-based custom comparator
        Arrays.sort(nums, (a, b) -> (b + a).compareTo(a + b));
        
        // Check for all-zero case
        if (nums[0].equals("0")) return "0";
        
        // Join all strings efficiently
        return String.join("", nums);
    }
    
    /**
     * Helper method to convert integer array to string array
     */
    public static String[] convertToStringArray(int[] intArray) {
        String[] stringArray = new String[intArray.length];
        for (int i = 0; i < intArray.length; i++) {
            stringArray[i] = String.valueOf(intArray[i]);
        }
        return stringArray;
    }
    
    /**
     * Demonstrates the algorithm with provided examples
     */
    public static void demonstrateExamples() {
        System.out.println("\n--- Example Demonstrations ---");
        
        // Example 1: [10, 2] -> "210"
        String[] example1 = {"10", "2"};
        String result1 = createLargestNumber(example1);
        System.out.println("Example 1: [10, 2] -> " + result1);
        
        // Example 2: [3, 30, 34, 5, 9] -> "9534330"
        String[] example2 = {"3", "30", "34", "5", "9"};
        String result2 = createLargestNumber(example2);
        System.out.println("Example 2: [3, 30, 34, 5, 9] -> " + result2);
        
        // Additional test case with zeros
        String[] example3 = {"0", "0"};
        String result3 = createLargestNumber(example3);
        System.out.println("Example 3: [0, 0] -> " + result3);
    }
}
