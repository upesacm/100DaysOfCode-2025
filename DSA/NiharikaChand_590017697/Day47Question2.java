import java.util.*;
class Day47Question2
{
    public static Queue<Integer> insert(Queue<Integer> q, int el) 
    {
        if (q instanceof LinkedList) 
        {
            ((LinkedList<Integer>) q).addFirst(el);
        }
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

        System.out.print("Enter element to insert at front: ");
        int insertElm = sc.nextInt();

        Queue<Integer> result = insert(q, insertElm);
        System.out.println("Output: " + result);
        sc.close();
    }
}

