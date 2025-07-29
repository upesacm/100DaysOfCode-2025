import java.util.*;
import java.util.LinkedList;
class Day44Question2
{
    public static void main(String[] args) 
    {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(1);
        queue.offer(2);
        queue.offer(3);
        queue.offer(4);

        System.out.println("Output: " + queue.size());
    }
}
