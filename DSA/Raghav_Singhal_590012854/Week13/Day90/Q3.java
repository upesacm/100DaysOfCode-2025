import java.util.*;

class Q3 {
    static int wordLadderLength(String beginWord, String endWord, List<String> wordList){
        Set<String> dict = new HashSet<>(wordList);
        if(!dict.contains(endWord)) return 0;
        Queue<String> q = new LinkedList<>();
        q.add(beginWord);
        int level = 1;
        while(!q.isEmpty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                String word = q.poll();
                char[] arr = word.toCharArray();
                for(int j=0;j<arr.length;j++){
                    char original = arr[j];
                    for(char c='a'; c<='z'; c++){
                        arr[j] = c;
                        String newWord = new String(arr);
                        if(newWord.equals(endWord)) return level+1;
                        if(dict.contains(newWord)){
                            q.add(newWord);
                            dict.remove(newWord);
                        }
                    }
                    arr[j] = original;
                }
            }
            level++;
        }
        return 0;
    }

    public static void main(String[] args){
        String begin = "hit", end = "cog";
        List<String> wordList = Arrays.asList("hot","dot","dog","lot","log","cog");
        System.out.println(wordLadderLength(begin,end,wordList));
    }
}