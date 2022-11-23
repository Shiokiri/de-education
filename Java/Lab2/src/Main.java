import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lab2.1
        Pay pay = new Pay(10000);
        pay.computePayment(12,0.15,0.0465);
        pay.computePayment(10,0.0475);
        pay.computePayment(20);

        // Lab2.2
        // Triangle
        Triangle t=new Triangle(3,4,5);
        System.out.println("Perimeter:"+t.ComputePerimeter());
        System.out.println("Area:"+t.getArea());
        t.setSideA(1000);
        System.out.println("new Area1:"+t.getArea());
        System.out.println("new Perimeter:"+t.getPerimeter());
        t.setSideA(6);
        t.setSideB(8);
        t.setSideC(10);
        System.out.println("new Area2:"+t.getArea());
        System.out.println("new Perimeter2:"+t.getPerimeter());
        // Lander
        Lander l=new Lander(10,20,10);
        System.out.println("Area:"+l.getArea());
        // Circle
        Circle c=new Circle(12.3);
        System.out.println("Area:"+c.getArea());
        System.out.println("Perimeter:"+c.getPerimeter());

        // Lab2.3
        List<Student> studentList = new ArrayList<>();
        studentList.add(new Student("小江","000001","男",1));
        studentList.add(new Student("小王","000002","男",1));
        studentList.add(new Student("小张","000003","女",1));
        studentList.add(new Student("小李","000004","男",2));
        studentList.add(new Student("小孙","000005","女",2));
        List<Course> courseList = new ArrayList<>();
        courseList.add(new Course("Java程序设计","000001",2));
        courseList.add(new Course("计算机组成原理","000002",3.5));
        courseList.add(new Course("数据结构","000003",2.5));
        List<Grade> gradeList = new ArrayList<>();
        gradeList.add(new Grade("000001", "000001",87.5));
        gradeList.add(new Grade("000001", "000002",84.5));
        gradeList.add(new Grade("000001", "000003",94));
        gradeList.add(new Grade("000002", "000001",91));
        gradeList.add(new Grade("000002", "000002",72));
        gradeList.add(new Grade("000002", "000003",89.5));
        gradeList.add(new Grade("000003", "000001",95));
        gradeList.add(new Grade("000003", "000002",80));
        gradeList.add(new Grade("000003", "000003",84));
        gradeList.add(new Grade("000004", "000001",87));
        gradeList.add(new Grade("000004", "000002",97));
        gradeList.add(new Grade("000004", "000003",87.5));
        gradeList.add(new Grade("000005", "000001",88));
        gradeList.add(new Grade("000005", "000002",79));
        gradeList.add(new Grade("000005", "000003",99.5));
        int[] clazzStudentNumber = new int[100];
        double[] clazzScore = new double [100];
        int maxClazz = 0;
        for (Grade grade : gradeList) {
            for(Student student : studentList) {
                maxClazz = Math.max(maxClazz, student.getClazz());
                if(grade.getStudentID() == student.getStudentID()) {
                    student.updateScore(grade.getScore());
                    for(Course course : courseList) {
                        if(grade.getCourseID() == course.getCourseID()) {
                            student.updateCredit(course.getCredit());
                            course.updateScore(grade.getScore());
                        }
                    }
                }
            }
        }
        Collections.sort(studentList);
        for(Student student : studentList) {
            System.out.printf("姓名：%s\n", student.getStudentName());
            System.out.printf("总成绩：%.2f\n", student.getTotalScore());
            System.out.printf("平均成绩：%.2f\n", student.getAverageScore());
            System.out.printf("总学分：%.2f\n", student.getTotalCredit());
            clazzStudentNumber[student.getClazz()] += 1;
            clazzScore[student.getClazz()] += student.getAverageScore();
        }
        for(int i = 1; i <= maxClazz; i++) {
            System.out.printf("班级：%d\n", i);
            System.out.printf("班级平均成绩：%.2f\n", clazzScore[i] / clazzStudentNumber[i]);
        }
        for(Course course : courseList) {
            System.out.printf("课程名：%s\n", course.getCourseName());
            System.out.printf("课程平均成绩：%.2f\n", course.getAverageScore());
        }
    }
}
