public class Q3 {

    public String removeKdigits(String num, int k) {
        if (k >= num.length()) return "0";

        StringBuilder stack = new StringBuilder();

        for (char c : num.toCharArray()) {
            while (k > 0 && stack.length() > 0 && stack.charAt(stack.length() - 1) > c) {
                stack.deleteCharAt(stack.length() - 1);
                k--;
            }
            stack.append(c);
        }

        while (k > 0 && stack.length() > 0) {
            stack.deleteCharAt(stack.length() - 1);
            k--;
        }

        int i = 0;
        while (i < stack.length() && stack.charAt(i) == '0') i++;

        String res = (i == stack.length()) ? "0" : stack.substring(i);
        return res;
    }

    public static void main(String[] args) {
        Q3 q = new Q3();
        System.out.println(q.removeKdigits("1432219", 3)); 
        System.out.println(q.removeKdigits("10200", 1));  
    }
}
