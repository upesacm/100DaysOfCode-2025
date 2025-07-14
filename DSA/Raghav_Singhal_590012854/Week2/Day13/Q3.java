public class Q3 {
    public static void main(String[] args) {
        String str="Hello World Programming";
        System.out.println(reversedStr(str));
    }
    public static String reversedStr(String str)
    {
        String[] arr = str.trim().split("\\s");
        StringBuilder sb = new StringBuilder();
        for (int i = arr.length - 1; i >= 0; i--) {
            sb.append(arr[i]);
            if (i != 0) {
                sb.append(" ");
            }
        }
        return sb.toString();
    }
}
