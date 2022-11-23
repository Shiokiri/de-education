public class Circle {
    private double r;
    private double Area;
    private double Perimeter;

    Circle(double r)
    {
        this.r=r;
        ComputePerimeter();
        ComputeArea();
    }
    public double getArea() {
        return Area;
    }
    public double getPerimeter() {
        return Perimeter;
    }
    public void ComputeArea()
    {
        Area=Math.PI*r*r;
    }
    public void ComputePerimeter()
    {
        Perimeter=Math.PI*2*r;
    }
}
