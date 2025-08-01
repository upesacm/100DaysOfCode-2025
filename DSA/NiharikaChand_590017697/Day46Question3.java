import java.util.*;
class Day46Question3
{
    public static Queue<Integer> merge(Queue<Integer> q1, Queue<Integer> q2) 
    {
        Queue<Integer> result = new LinkedList<>();

        for (int num : q1) 
        {
            result.offer(num);
        }
        for (int num : q2) 
        {
            result.offer(num);
        }
        return result;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> q1 = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();

        System.out.print("Enter number of elements in Queue 1: ");
        int n1 = sc.nextInt();
        System.out.println("Enter integers for Queue 1:");
        for (int i = 0; i < n1; i++) 
        {
            q1.offer(sc.nextInt());
        }
        System.out.print("Enter number of elements in Queue 2: ");
        int n2 = sc.nextInt();
        System.out.println("Enter integers for Queue 2:");
        for (int i = 0; i < n2; i++) 
        {
            q2.offer(sc.nextInt());
        }
        Queue<Integer> mergedQueue = merge(q1, q2);
        System.out.println("Merged Queue: " + mergedQueue);
    }
}

