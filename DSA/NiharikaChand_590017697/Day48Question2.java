import java.util.*;
class Day48Question2
{
    public static boolean checkUnique(Queue<Integer> q) 
    {
        Set<Integer> c = new HashSet<>();

        for (int el : q) 
        {
            if (c.contains(el)) 
            {
                return false; 
            }
            c.add(el);
        }
        return true; 
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

        boolean result = checkUnique(queue);
        System.out.println("Output: " + result);
    }
}

