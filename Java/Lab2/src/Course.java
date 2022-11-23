public class Course {
    private String courseName;
    private String courseID;
    private double credit;

    private double totalScore;
    private int studentNumber;
    private double averageScore;

    Course(String courseName, String courseID, double credit) {
        this.courseName = courseName;
        this.courseID = courseID;
        this.credit = credit;
    }
    public String getCourseName() {
        return courseName;
    }
    public String getCourseID() {
        return courseID;
    }
    public double getCredit() {
        return credit;
    }
    public void updateScore(double score) {
        totalScore += score;
        studentNumber += 1;
        averageScore = totalScore / studentNumber;
    }
    public double getAverageScore() {
        return averageScore;
    }
}
