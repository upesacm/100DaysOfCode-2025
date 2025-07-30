import java.util.*;
class Day45Question1
{
    public static int sum(Queue<Integer> queue) 
    {
        int size = queue.size();
        int s= 0;

        for (int i = 0; i < size; i++) 
        {
            int val = queue.poll();
            s += val;
            queue.offer(val);
        }
        return s;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> q = new LinkedList<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an element: ");
            q.offer(sc.nextInt());
        }

        int result = sum(q);
        System.out.println("Output: " + result);
    }
}