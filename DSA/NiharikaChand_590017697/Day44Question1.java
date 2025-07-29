import java.util.*;
class Day44Question1
{
    public static void display(Queue<Integer> queue) 
    {
        Queue<Integer> temp = new LinkedList<>();
        while (!queue.isEmpty()) 
        {
            int element = queue.poll();
            System.out.print(element + " ");
            temp.offer(element);
        }

        while (!temp.isEmpty()) 
        {
            queue.offer(temp.poll());
        }
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) 
        {
            queue.offer(sc.nextInt());
        }

        System.out.println("Output: ");
        display(queue);
        sc.close();
    }
}
