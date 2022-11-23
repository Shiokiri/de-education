public class Grade {
    private String studentID;
    private String courseID;
    private double score;

    Grade(String studentID, String courseID, double score) {
        this.studentID = studentID;
        this.courseID = courseID;
        this.score = score;
    }
    public String getStudentID() {
        return studentID;
    }
    public String getCourseID() {
        return courseID;
    }
    public double getScore() {
        return score;
    }
}