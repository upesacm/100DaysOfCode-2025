import java.util.Stack;

public class Q2 {

    public String decodeString(String s) {
        Stack<Integer> numStack = new Stack<>();
        Stack<StringBuilder> strStack = new Stack<>();
        
        StringBuilder currentString = new StringBuilder();
        int currentNum = 0;

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                currentNum = currentNum * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(currentNum);
                strStack.push(currentString);
                
                currentNum = 0;
                currentString = new StringBuilder();
            } else if (c == ']') {
                int repeatTimes = numStack.pop(); 
                StringBuilder prevString = strStack.pop(); 

                for (int i = 0; i < repeatTimes; i++) {
                    prevString.append(currentString);
                }
                
                currentString = prevString; 
            } else {
                currentString.append(c);
            }
        }
        
        return currentString.toString();
    }

    public static void main(String[] args) {
        DecodeString decoder = new DecodeString();

        String s1 = "3[a]2[bc]";
        System.out.println("Input: " + s1 + ", Output: " + decoder.decodeString(s1)); 

        
    }
}
