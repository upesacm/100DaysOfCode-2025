import java.util.*;

public class Question2 {

    public static List<Integer> getAllAnagrams(String str, String pattern) {
        if (str == null || str.length() == 0 || pattern == null || pattern.length() == 0) {
            return new ArrayList<>();
        }

        Map<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < pattern.length(); i++) {
            map.put(pattern.charAt(i), map.getOrDefault(pattern.charAt(i), 0) + 1);
        }

        int matchedElement = 0;
        int start = 0;
        List<Integer> anagramStartingIndexes = new ArrayList<>();

        for (int i = 0; i < str.length(); i++) {
            char currentChar = str.charAt(i);

            if (map.containsKey(currentChar)) {
                map.put(currentChar, map.get(currentChar) - 1);
                if (map.get(currentChar) == 0) {
                    matchedElement++;
                }
            }

            if (matchedElement == map.size()) {
                anagramStartingIndexes.add(start);
            }

            if (i >= pattern.length() - 1) {
                char charAtStart = str.charAt(start++);
                if (map.containsKey(charAtStart)) {
                    if (map.get(charAtStart) == 0) {
                        matchedElement--;
                    }
                    map.put(charAtStart, map.get(charAtStart) + 1);
                }
            }
        }

        return anagramStartingIndexes;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the main string: ");
        String str = sc.nextLine();

        System.out.print("Enter the pattern string: ");
        String pattern = sc.nextLine();

        List<Integer> result = getAllAnagrams(str, pattern);

        System.out.println(result.size());
        
        sc.close();
    }
}
