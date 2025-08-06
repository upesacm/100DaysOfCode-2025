import java.util.*;

public class Question1 {

    public static int longestKSubstr(String s, int k) {
        int i = 0, j = 0;
        HashMap<Character, Integer> map = new HashMap<>();
        int max = -1;

        while (j < s.length()) {
            map.put(s.charAt(j), map.getOrDefault(s.charAt(j), 0) + 1);

            while (map.size() > k) {
                map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) - 1);
                if (map.get(s.charAt(i)) == 0) {
                    map.remove(s.charAt(i));
                }
                i++;
            }

            if (map.size() == k) {
                max = Math.max(max, j - i + 1);
            }

            j++;
        }

        return max;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the string: ");
        String s = sc.nextLine();

        System.out.print("Enter value of k: ");
        int k = sc.nextInt();

        int result = longestKSubstr(s, k);
        System.out.println(result);

        sc.close();
    }
}
