public class Lander {
    private double upperBottom;
    private double lowerBottom;
    private double height;
    private double Area;
    Lander(double upperBottom,double lowerBottom,double height)
    {
        this.upperBottom=upperBottom;
        this.lowerBottom=lowerBottom;
        this.height=height;
        ComputeArea();
    }

    public double getArea() {
        return Area;
    }
    public void ComputeArea()
    {
        Area=height*(upperBottom+lowerBottom)/2;
    }
}
