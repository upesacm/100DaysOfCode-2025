import java.util.*;
class Day47Question1
{
    public static Queue<Integer> insert(Queue<Integer> q, int el) 
    {
        q.offer(el); 
        return q;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> q = new LinkedList<>();

        System.out.print("Enter number of elements in the queue: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an element:");
            q.offer(sc.nextInt());
        }

        System.out.print("Enter element to insert at rear: ");
        int insertElement = sc.nextInt();

        Queue<Integer> result = insert(q, insertElement);
        System.out.println("Output: " + result);
        sc.close();
    }
}

