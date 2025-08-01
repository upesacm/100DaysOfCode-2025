import java.util.*;
class Day47Question3
{
    public static void find(Queue<Integer> q) 
    {
        if (q.isEmpty()) 
        {
            System.out.println("The queue is empty.");
            return;
        }
        int front = q.peek();
        int rear = 0;
        for (int item : q) 
        {
            rear = item;
        }
        System.out.println("Output: ");
        System.out.println("Front: " + front + ", Rear: " + rear);
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> q = new LinkedList<>();
        System.out.print("Enter number of elements in the queue: ");
        int n = sc.nextInt();
        if (n == 0) 
        {
            find(q);
        } 
        else 
        {
            for (int i = 0; i < n; i++) 
            {
                System.out.println("Enter an element:");
                q.offer(sc.nextInt());
            }
            find(q);
        }
        sc.close();
    }
}
