import java.util.LinkedList;
import java.util.Scanner;

public class Q3 {

    public static void deleteMiddle(LinkedList<Integer> list) {
        if (list == null || list.size() <= 1) {
            list.clear();
            return;
        }

        int middleIndex = list.size() / 2; 
        list.remove(middleIndex);
    }

    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter size of linked list: ");
        int size = scanner.nextInt();

        System.out.println("Enter " + size + " values:");
        for (int i = 0; i < size; i++) {
            int value = scanner.nextInt();
            list.add(value);
        }

        System.out.println("Original Linked List: " + list);

        deleteMiddle(list);

        System.out.println("After Deleting Middle Node: " + list);

        scanner.close();
    }
}
