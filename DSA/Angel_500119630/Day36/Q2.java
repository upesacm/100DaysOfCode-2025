public class Q2 {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        HashMap<Character,Character> cto = new HashMap<>();
        cto.put(')','(');
        cto.put('}','{');
        cto.put(']','[');
        for(char c : s.toCharArray()){
            if(cto.containsKey(c)){
                if(!st.isEmpty() && st.peek() == cto.get(c)){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                st.push(c);
            }
        }
         return st.isEmpty();
    }
}
