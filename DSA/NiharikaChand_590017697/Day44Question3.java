import java.util.*;
import java.util.LinkedList;
class Day44Question3
{
    public static boolean checkEmpty(Queue<Integer> queue) 
    {
        return queue.isEmpty();
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();

        System.out.print("Enter number of elements to insert into queue: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an element:");
            queue.offer(sc.nextInt());
        }

        System.out.println("Output: " + checkEmpty(queue));
        sc.close();
    }
}
