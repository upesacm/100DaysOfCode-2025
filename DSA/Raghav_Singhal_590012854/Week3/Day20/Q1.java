import java.util.*;
class Student {
    String name;
    int grade;
    Student(String name, int grade) {
        this.name = name;
        this.grade = grade;
    }
    @Override public String toString() {
        return "(\"" + name + "\", " + grade + ")";
    }
}
public class Q1
{
    public static void main(String[] args) {
        List<Student> students = new ArrayList<>();
        students.add(new Student("Ram", 85));
        students.add(new Student("Bhuvi", 92));
        students.add(new Student("Chetan", 78));

        for (int i = 0; i < students.size() - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < students.size(); j++) {
                if (students.get(j).grade > students.get(minIdx).grade) {
                    minIdx = j;
                }
            }
            Student temp = students.get(i);
            students.set(i, students.get(minIdx));
            students.set(minIdx, temp);
        }
        System.out.println(students.toString());
    }
}