import java.util.*;

public class Day_90_Question_3 {

    // Returns length of shortest transformation sequence from beginWord to endWord
    public static int ladderLength(String beginWord, String endWord, java.util.List<String> wordList) {
        Set<String> dict = new HashSet<>(wordList);
        if (!dict.contains(endWord)) return 0;
        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);
        int steps = 1;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String word = queue.poll();
                char[] arr = word.toCharArray();
                for (int j = 0; j < arr.length; j++) {
                    char orig = arr[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        arr[j] = c;
                        String next = new String(arr);
                        if (next.equals(endWord)) return steps + 1;
                        if (dict.contains(next)) {
                            queue.offer(next);
                            dict.remove(next);
                        }
                    }
                    arr[j] = orig;
                }
            }
            steps++;
        }
        return 0;
    }

    public static void main(String[] args) {
        String begin1 = "hit", end1 = "cog";
        java.util.List<String> wl1 = java.util.Arrays.asList("hot","dot","dog","lot","log","cog");
        System.out.println(ladderLength(begin1, end1, wl1)); // Output: 5

        String begin2 = "hit", end2 = "cog";
        java.util.List<String> wl2 = java.util.Arrays.asList("hot","dot","dog","lot","log");
        System.out.println(ladderLength(begin2, end2, wl2)); // Output: 0
    }
}
