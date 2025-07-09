import java.util.LinkedList;
public class Q2 {
    public static void removeDuplicates(LinkedList<Integer> list) {
        if (list == null || list.size() <= 1) return;

        int i = 0;
        while (i < list.size() - 1) {
            if (list.get(i).equals(list.get(i + 1))) {
                list.remove(i + 1);
            } else {
                i++; 
            }
        }
    }

    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        list.add(2);
        list.add(2);
        list.add(4);
        list.add(5);

        removeDuplicates(list);
        System.out.println("After Removing Duplicates: " + list); 
    }
}
