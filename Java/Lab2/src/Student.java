public class Student implements Comparable<Student> {
    private String studentName;
    private String studentID;
    private String gender;
    private int clazz;

    private double totalScore;
    private int courseNumber;
    private double averageScore;
    private double totalCredit;

    Student(String studentName, String studentID, String gender, int clazz) {
        this.studentName = studentName;
        this.studentID = studentID;
        this.gender = gender;
        this.clazz = clazz;
    }
    @Override
    public int compareTo(Student comparestu) {
        return this.averageScore - comparestu.averageScore < 0 ? 1 : -1;
    }
    public String getStudentName() {
        return studentName;
    }
    public String getStudentID() {
        return studentID;
    }
    public String getGender() {
        return gender;
    }
    public int getClazz() {
        return clazz;
    }
    public void updateScore(double score) {
        totalScore += score;
        courseNumber += 1;
        averageScore = totalScore / courseNumber;
    }
    public void updateCredit(double credit) {
        totalCredit += credit;
    }
    public double getTotalScore() {
        return totalScore;
    }
    public double getAverageScore() {
        return averageScore;
    }
    public double getTotalCredit() {
        return totalCredit;
    }
}
