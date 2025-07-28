import java.util.Stack;

public class Q2{

    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        Stack<Integer> st = new Stack<>();
        int max = 0;

        for (int i = 0; i <= n; i++) 
        {
            int curr = (i == n) ? 0 : heights[i]; 

            while (!st.isEmpty() && curr < heights[st.peek()]) 
            {
                int h = heights[st.pop()];
                int right = i;
                int left = st.isEmpty() ? -1 : st.peek();
                int area = h * (right - left - 1);
                max = Math.max(max, area);
            }
            st.push(i);
        }
        return max;
    }

    public static void main(String[] args) {
        Q2 solver = new Q2();
        int[] h1 = {2, 1, 5, 6, 2, 3};   

        System.out.println(solver.largestRectangleArea(h));
    }
}
