import java.util.*;
public class Q2 {
   public static int[] countEvenOdd(Queue<Integer> queue) {
        int even = 0;
        int odd = 0;
        Queue<Integer> temp = new LinkedList<>(queue);
        while (!temp_list.isEmpty()) {
            int value = temp.poll();
            if (value % 2 == 0){
              even++;
            }
            else {
              odd++;
            }
        }
        return new int[]{even, odd};
    }
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(List.of(1, 2, 3, 4, 5));
        int[] result = countEvenOdd(queue);
        System.out.println("Even: " + result[0] + ", Odd: " + result[1]);
    }
   
}
