import java.util.*;
class Day45Question2
{
    public static boolean checkEqual(Queue<Integer> q1, Queue<Integer> q2) 
    {
        if (q1.size() != q2.size()) return false;

        int size = q1.size();
        boolean isEqual = true;

        for (int i = 0; i < size; i++) 
        {
            int val1 = q1.poll();
            int val2 = q2.poll();

            if (val1 != val2) 
            {
                isEqual = false;
            }

            q1.offer(val1);
            q2.offer(val2);
        }

        return isEqual;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> q1 = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();

        System.out.print("Enter number of elements for both queues: ");
        int n = sc.nextInt();

        System.out.println("Enter elements for Queue 1:");
        for (int i = 0; i < n; i++) 
        {
            q1.offer(sc.nextInt());
        }
        System.out.println("Enter elements for Queue 2:");
        for (int i = 0; i < n; i++) 
        {
            q2.offer(sc.nextInt());
        }

        if (checkEqual(q1, q2)) 
        {
            System.out.println("Yes");
        } 
        else 
        {
            System.out.println("No");
        }
     sc.close();
    }
}
