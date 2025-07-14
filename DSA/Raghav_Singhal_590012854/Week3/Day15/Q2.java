import java.util.*;
public class Q2 {
    public static void main(String[] args) 
    {
        String arr[]={"java", "python", "c", "javascript"};
        System.out.println(Arrays.toString(bubbleSort(arr)));
    }
    public static String[] bubbleSort(String arr[]) 
    {
        int n = arr.length;
        boolean check;
        for (int i = 0; i < n - 1; i++) {
            check = false;
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j].length() > arr[j + 1].length()) {
                    String temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    check = true;
                }
            }
            if (!check)
                break;
        }
        return arr;
    }
}
