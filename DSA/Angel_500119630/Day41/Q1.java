class Q1 {
    public String removeDuplicates(String s) {
        Stack<Character> withoutDup = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);

            
            if (!withoutDup.isEmpty() && currentChar == withoutDup.peek()) {
                withoutDup.pop();
            } else {
                
                withoutDup.push(currentChar);
            }
        }

        String res = "";
        while(!withoutDup.isEmpty()){
            res = withoutDup.pop() + res; 

        }
        return res;
    }
}
