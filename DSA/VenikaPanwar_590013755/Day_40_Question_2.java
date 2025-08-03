import java.util.Scanner;
import java.util.Stack;

public class Day_40_Question_2 {
    public static int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0;
        int n = heights.length;

        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while (!stack.isEmpty() && h < heights[stack.peek()]) {
                int height = heights[stack.pop()];
                int width = stack.isEmpty() ? i : i - 1 - stack.peek();
                int area = height * width;
                maxArea = Math.max(maxArea, area);
            }
            stack.push(i);
        }

        return maxArea;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of bars: ");
        int n = sc.nextInt();
        int[] heights = new int[n];
        System.out.println("Enter bar heights:");
        for (int i = 0; i < n; i++) heights[i] = sc.nextInt();

        int result = largestRectangleArea(heights);
        System.out.println("Largest Rectangle Area: " + result);
    }
}
