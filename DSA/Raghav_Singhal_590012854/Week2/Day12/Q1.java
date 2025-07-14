public class Q1 {
    public static void main(String[] args) {
        String String1= "waterbottle", String2= "erbottlewat";
        System.out.println(isRotationOf(String1,String2));
    }
    public static boolean isRotationOf(String str1,String str2)
    {
        str1+=str1;
        return str1.contains(str2);
    }
}
