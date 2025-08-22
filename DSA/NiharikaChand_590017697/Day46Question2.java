import java.util.*;
class Day46Question2 
{
    public static void count(Queue<Integer> queue) 
    {
        int eCount = 0;
        int oCount = 0;
        Queue<Integer> temp = new LinkedList<>();

        while (!queue.isEmpty()) {
            int curr = queue.poll();

            if (curr % 2 == 0) 
            {
                eCount++;
            } 
            else 
            {
                oCount++;
            }

            temp.offer(curr); 
        }

        while (!temp.isEmpty()) 
        {
            queue.offer(temp.poll());
        }
        System.out.println("Output: ");
        System.out.println("Even: " + eCount + ", Odd: " + oCount);
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> q = new LinkedList<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an integers:");
            q.offer(sc.nextInt());
        }

        count(q);
    }
}