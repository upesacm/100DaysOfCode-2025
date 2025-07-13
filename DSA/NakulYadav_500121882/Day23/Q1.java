import java.util.LinkedList;

public class question1 {
    public static int findKthFromEnd(LinkedList<Integer> list, int k) {
        if (k <= 0 || k > list.size()) {
            return -1;
        }
        return list.get(list.size() - k); 
    }

    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);

        int k = 2;
        int result = findKthFromEnd(list, k);
        System.out.println("Kth node from end is: " + result); 
    }
}
