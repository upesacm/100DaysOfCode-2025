public class Q1 
{
    public static void main(String args[])
    {
        String String1= "Hello", String2= "hello";
        System.out.println(isEqual(String1,String2)[0]+", "+isEqual(String1,String2)[1]+", "+comesFirst(String1,String2));
    }
    public static String[] isEqual(String str1,String str2)
    {
        String eq,caseEq;
        eq=str1.equals(str2)?"Equal":"Not equal";
        caseEq=str1.equalsIgnoreCase(str2)?"Equal ignoring cases":"Not equal ignoring cases";
        return new String[]{eq,caseEq};
    }
    public static String comesFirst(String str1,String str2)
    {
        int min=str1.length()>str2.length()?str2.length():str1.length();
        for (int i = 0; i < min; i++) {
            if((int)str1.charAt(i)<(int)str2.charAt(i))
                return "\""+str1+"\""+" comes before "+"\""+str2+"\"";
            else
                return "\""+str2+"\""+" comes before "+"\""+str1+"\"";
        }
        if(str1.length()<str2.length())
            return "\""+str1+"\""+" comes before "+"\""+str2+"\"";
        else if(str1.length()>str2.length())
            return "\""+str2+"\""+" comes before "+"\""+str1+"\"";
        return "Strings are identical";
    }
}