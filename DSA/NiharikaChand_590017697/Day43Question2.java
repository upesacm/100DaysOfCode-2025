import java.util.*;
import java.util.LinkedList;
class Day43Question2
{
    public static List<String> generateBinaryNumbers(int n) 
    {
        List<String> result = new ArrayList<>();
        Queue<String> queue = new LinkedList<>();

        queue.offer("1");

        for (int i = 0; i < n; i++) 
        {
            String current = queue.poll();
            result.add(current);

            queue.offer(current + "0");
            queue.offer(current + "1");
        }
        return result;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter value of n: ");
        int n = sc.nextInt();
        List<String> binaryList = generateBinaryNumbers(n);
        System.out.println("Output: ");
        for (int i = 0; i < binaryList.size(); i++) 
        {
            System.out.print(binaryList.get(i) + " ");
        }

    }
}
