import java.util.*;
import java.util.LinkedList;
class Day48Question3
{
    public static Map<Integer, Integer> countFreq(Queue<Integer> q) 
    {
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int el : q) 
        {
            freqMap.put(el, freqMap.getOrDefault(el, 0) + 1);
        }

        return freqMap;
    }

    public static void main(String args[]) 
    {
        Scanner scanner = new Scanner(System.in);
        Queue<Integer> q = new LinkedList<>();
        System.out.print("Enter number of elements in the queue: ");
        int n = scanner.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an element:");
            q.offer(scanner.nextInt());
        }

        Map<Integer, Integer> freqMap = countFreq(q);
        System.out.println("Output:");
        System.out.print("{");

        int count = 0;
        int size = freqMap.size();

        for (Map.Entry<Integer, Integer> entry : freqMap.entrySet()) 
        {
            System.out.print(entry.getKey() + ": " + entry.getValue());
            count++;
            if (count < size) 
            {
                System.out.print(", ");
            }
        }
        System.out.println("}");
    }
}

