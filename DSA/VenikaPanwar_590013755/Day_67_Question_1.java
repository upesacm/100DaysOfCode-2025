import java.util.*;

public class Day_67_Question_1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        
        String[] numbers = new String[n];
        System.out.println("Enter the numbers:");
        
        for (int i = 0; i < n; i++) {
            numbers[i] = scanner.next();
        }
        
        String result = arrangeForLargestNumber(numbers);
        System.out.println("Largest possible number: " + result);
        
        scanner.close();
    }
    
    public static String arrangeForLargestNumber(String[] nums) {
        // Handle edge case of all zeros
        if (nums == null || nums.length == 0) {
            return "0";
        }
        
        // Custom sorting using comparator
        Arrays.sort(nums, new Comparator<String>() {
            @Override
            public int compare(String a, String b) {
                // Compare concatenated results: a+b vs b+a
                String order1 = a + b;
                String order2 = b + a;
                return order2.compareTo(order1); // Descending order
            }
        });
        
        // Check if result would be all zeros
        if (nums[0].equals("0")) {
            return "0";
        }
        
        // Build the final result
        StringBuilder result = new StringBuilder();
        for (String num : nums) {
            result.append(num);
        }
        
        return result.toString();
    }
    
    // Alternative implementation with lambda expression
    public static String arrangeForLargestNumberLambda(String[] nums) {
        if (nums == null || nums.length == 0) return "0";
        
        Arrays.sort(nums, (a, b) -> (b + a).compareTo(a + b));
        
        if (nums[0].equals("0")) return "0";
        
        return String.join("", nums);
    }
}