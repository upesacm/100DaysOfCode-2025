import java.util.*;
 class Day46Question1
{
    public static int findMin(Queue<Integer> queue) 
    {
        if (queue.isEmpty()) 
        {
            throw new NoSuchElementException("Queue is empty");
        }

        int min = Integer.MAX_VALUE;
        Queue<Integer> temp = new LinkedList<>();

        while (!queue.isEmpty()) 
        {
            int current = queue.poll();
            if (current < min) 
            {
                min = current;
            }
            temp.offer(current);
        }

        while (!temp.isEmpty()) 
        {
            queue.offer(temp.poll());
        }
        return min;
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
        int min = findMin(q);
        System.out.println("Output: " + min);
    }
}

