import java.util.*;
class Day48Question1
{
    public static Queue<Integer> remove(Queue<Integer> q, int x) 
    {
        Queue<Integer> result = new LinkedList<>();
        
        for (int el : q) 
        {
            if (el != x) 
            {
                result.offer(el);
            }
        }
        return result;
    }

    public static void main(String args[]) 
    {
        Scanner scanner = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();
        System.out.print("Enter number of elements in the queue: ");
        int n = scanner.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an element:");
            queue.offer(scanner.nextInt());
        }

        System.out.print("Enter the element to remove: ");
        int x = scanner.nextInt();
        Queue<Integer> result = remove(queue, x);
        System.out.println("Output: " + result);
    }
}

