import java.util.*;
class Day45Question3
{
    public static int findMax(Queue<Integer> queue) 
    {
        int size = queue.size();
        int max = Integer.MIN_VALUE;

        for (int i = 0; i < size; i++) 
        {
            int val = queue.poll();
            if (val > max) 
            {
                max = val;
            }
            queue.offer(val); 
        }
        return max;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an element:");
            queue.offer(sc.nextInt());
        }

        int maxElement = findMax(queue);
        System.out.println("Output: " + maxElement);
        sc.close();
    }
}


