import java.util.*;
class Day43Question1
{
    public static Queue<Integer> revFirst(Queue<Integer> queue, int k) 
    {
        if (queue == null || k <= 0 || k > queue.size()) return queue;
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < k; i++) 
        {
            stack.push(queue.remove());
        }

        while (!stack.isEmpty()) 
        {
            queue.add(stack.pop());
        }

        int size = queue.size();
        for (int i = 0; i < size - k; i++) 
        {
            queue.add(queue.remove());
        }
        return queue;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();

        System.out.print("Enter queue size: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an elements:");
            queue.add(sc.nextInt());
        }

        System.out.print("Enter value of k: ");
        int k = sc.nextInt();

        Queue<Integer> result = revFirst(queue, k);
        System.out.println("Output: ");
        System.out.println(result);
    }
}
