import java.util.*;
class Day40Question2
{
    public static int calLargestArea(int ht[]) 
    {
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0;
        int n = ht.length;

        for (int i = 0; i <= n; i++) 
        {
            int currHeight;
            if (i == ht.length) 
            {
                currHeight = 0;
            }   
            else 
            {
                currHeight = ht[i];
            }


            while (!stack.isEmpty() && currHeight < ht[stack.peek()]) 
            {
                int h = ht[stack.pop()];
                int w;

                if (stack.isEmpty()) 
                {
                    w = i; 
                } 
                else 
                {
                    w = i - stack.peek() - 1; 
                }

                int area = h * w;
                maxArea = Math.max(maxArea, area);
            }

            stack.push(i);
        }
        return maxArea;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of histogram bars: ");
        int n = sc.nextInt();

        int ht[] = new int[n];
        System.out.println("Enter the heights of the bars:");
        for (int i = 0; i < n; i++) 
        {
            ht[i] = sc.nextInt();
        }

        int maxArea = calLargestArea(ht);
        System.out.println("Output: " + maxArea);
    }
}

